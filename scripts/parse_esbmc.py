import pandas as pd
import os
import re

CURRENT_DIRECTORY = os.getcwd()
# ESBMC_OUTPUT_PATH = os.path.join(CURRENT_DIRECTORY, "wizard_esbmc")
# TARGET_FILE_NAME = "data/wizard_coder_statuses.csv"

#Four Cases:
# VERIFICATION SUCCESSFUL
# VERIFICATION UNKNOWN
# ERROR: Message from unrecognized k-induction child process
# VERIFICATION FAILED: Violated property
STATUS_DICT = {"VERIFICATION SUCCESSFUL": "VERIFICATION SUCCESSFUL",
               "VERIFICATION FAILED": "VERIFICATION FAILED",
               "VERIFICATION UNKNOWN": "VERIFICATION UNKNOWN",
               "ERROR": "ERROR"}




def get_status(esbmc_text):
    for key, value in STATUS_DICT.items():
        if key in esbmc_text:
            return value
    return "could not parse"

def process_esbmc_output(file_path):
    with open(file_path, "r") as esbmc_text_file:
        esbmc_text = esbmc_text_file.read()
        prompt_id = os.path.basename(file_path).split(".")[0]
        status = get_status(esbmc_text)
        return [prompt_id, status]
    

def extract_violations(esbmc_output_directory):
    violations = []

    for file in os.listdir(esbmc_output_directory):
        file_path = os.path.join(esbmc_output_directory, file)
        with open(file_path, "r") as esbmc_text_file:
            esbmc_text = esbmc_text_file.read()
            prompt_id = file.split(".")[0]
            if "VERIFICATION FAILED" in esbmc_text:
                pattern1 = re.compile(r'Violated property:\s+file ([^\n]+)\n\s+([^\n]+)', re.DOTALL)
                matches1 = pattern1.findall(esbmc_text)
                if matches1:
                    for match in matches1:
                        violations.append([prompt_id] + list(match))
                else: #MUST FIX, CAN TAG WITH "invalidated dynamic object freed?"
                    pattern2 = re.compile(r'Violated property:\s+([^\n]+)', re.DOTALL)
                    bug = pattern2.findall(esbmc_text)
                    #find way to identify line later, should not make it into two different bugs bc it's the same line
                    violations.append([prompt_id] + ["ugh fill this in later", bug])
            else:
                next
    
    return violations


def clean_violations(violations, target_file):
    failed_verification = pd.DataFrame(violations, columns = ['Prompt ID', 'Line', 'Bug'])
    print(failed_verification.head())
    print(failed_verification.shape)
    failed_verification['Bug'] = failed_verification['Bug'].astype(str)
    cleaned_failed_verification = failed_verification.drop_duplicates()
    print(cleaned_failed_verification.shape)
    prompts = pd.read_csv("scripts/LLMSecEval-prompts.csv")
    bugs = pd.merge(cleaned_failed_verification, prompts, on = "Prompt ID", how = "inner")
    bugs.to_csv(target_file)



# def main():
    
#     status_list = [process_esbmc_output(os.path.join(ESBMC_OUTPUT_PATH, file)) for file in os.listdir(ESBMC_OUTPUT_PATH)]
    
#     checked_code_data = pd.DataFrame(status_list, columns = ["Prompt ID", "ESBMC_Status"])

#     checked_code_data.set_index('Prompt ID', inplace=True)

#     print(checked_code_data.head())
#     print(checked_code_data.shape)

#     prompts = pd.read_csv("scripts/LLMSecEval-prompts.csv")

#     statuses = pd.merge(checked_code_data, prompts, on = "Prompt ID", how = "inner")


#     statuses.to_csv(os.path.join(CURRENT_DIRECTORY, TARGET_FILE_NAME))

    # CURRENT_DIRECTORY = os.getcwd()
    # ESBMC_OUTPUT_PATH = os.path.join(CURRENT_DIRECTORY, "esbmc_output")

    # STATUS_MAP = {
    #     "VERIFICATION SUCCESSFUL": "VERIFICATION SUCCESSFUL",
    #     "VERIFICATION UNKNOWN": "VERIFICATION UNKNOWN",
    #     "ERROR": "ERROR"
    # }

    # def get_esbmc_status(esbmc_text):
    #     for key, value in STATUS_MAP.items():
    #         if key in esbmc_text:
    #             return value
    #     return "VERIFICATION FAILED"

    # def process_esbmc_output(file_path):
    #     with open(file_path, "r") as esbmc_text_file:
    #         esbmc_text = esbmc_text_file.read()
    #         prompt_id = os.path.basename(file_path).split(".")[0]
    #         status = get_esbmc_status(esbmc_text)
    #         return [prompt_id, status]

    # status_list = [process_esbmc_output(os.path.join(ESBMC_OUTPUT_PATH, file)) for file in os.listdir(ESBMC_OUTPUT_PATH)]

    # checked_code_data = pd.DataFrame(status_list, columns=["Prompt ID", "ESBMC_Status"])

    # prompts = pd.read_csv("scripts/LLMSecEval-prompts.csv")

    # statuses = pd.merge(checked_code_data, prompts, on="Prompt ID", how="inner")

    # statuses.to_csv(os.path.join(CURRENT_DIRECTORY, "data/statuses.csv"), index=False)

# if __name__ == "__main__":
#     main()
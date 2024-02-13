import pandas as pd
import os
import re

CURRENT_DIRECTORY = os.getcwd()
ESBMC_OUTPUT_PATH = CURRENT_DIRECTORY, "esbmc_output"

#Four Cases:
# VERIFICATION SUCCESSFUL
# VERIFICATION UNKNOWN
# ERROR: Message from unrecognized k-induction child process
# VERIFICATION FAILED: Violated property
status_dict = {"VERIFICATION SUCCESSFUL": "VERIFICATION SUCCESSFUL",
               "VERIFICATION UNKNOWN": "VERIFICATION UNKNOWN",
               "ERROR": "ERROR"}

status_list = []

for file in os.listdir(os.path.join(ESBMC_OUTPUT_PATH)):
    file_path = os.path.join(ESBMC_OUTPUT_PATH, file)
    with open(file_path, "r") as esbmc_text_file:
        esbmc_text = esbmc_text_file.read()
        prompt_id = file.split(".")[0]
        status = next((value for key, value in status_dict.items() if key in esbmc_text), "VERIFICATION FAILED")
        status_list.append([prompt_id, status])

        

            

checked_code_data = pd.DataFrame(status_list, columns = ["Prompt ID", "ESBMC_Status"])

print(checked_code_data.head())
print(checked_code_data.shape)

prompts = pd.read_csv("scripts/LLMSecEval-prompts.csv")

statuses = pd.merge(checked_code_data, prompts, on = "Prompt ID", how = "inner")


statuses.to_csv(os.path.join(CURRENT_DIRECTORY, "data/statuses.csv"))

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

import os
import re
import pandas as pd

CURRENT_DIRECTORY = os.getcwd()

def process_esbmc_file(file_path):
    with open(file_path, "r") as esbmc_text_file:
        esbmc_text = esbmc_text_file.read()
        prompt_id = os.path.splitext(os.path.basename(file_path))[0]
        violations = []
        if "VERIFICATION FAILED" in esbmc_text:
            # Original pattern for 'Violated property'
            pattern1 = re.compile(r'Violated property:\s+file ([^\n]+)\n\s+([^\n]+)', re.DOTALL)
            matches1 = pattern1.findall(esbmc_text)
            if matches1:
                for match in matches1:
                    violations.append([prompt_id] + list(match))
            # Additional pattern for 'Failed to allocate memory'
            pattern2 = re.compile(r'State \d+ file ([^\n]+)\n-{50,}\n\s+new_person = 0\n([^State]+)', re.DOTALL)
            matches2 = pattern2.findall(esbmc_text)
            if matches2:
                for match in matches2:
                    line, bug = match[0].strip(), match[1].strip()
                    violations.append([prompt_id, line, bug])
            # Additional pattern for 'Violated property' after 'State \d+ thread \d+'
            pattern3 = re.compile(r'State \d+ thread \d+\n-{50,}\nViolated property:\s+([^\n]+)\n\s+([^\n]+)', re.DOTALL)
            matches3 = pattern3.findall(esbmc_text)
            if matches3:
                for match in matches3:
                    line, bug = match[0].strip(), match[1].strip()
                    violations.append([prompt_id, line, bug])
        return violations

# Example usage: Apply the function to files with a certain condition
directory_path = os.path.join(CURRENT_DIRECTORY, "esbmc_output")
files_to_process = [file for file in os.listdir(directory_path) if file.endswith(".txt")]


failed_verification_list = []
for file_name in files_to_process:
    file_path = os.path.join(directory_path, file_name)
    violations_result = process_esbmc_file(file_path)
    failed_verification_list.append(violations_result)
    
    
failed_verification = pd.DataFrame(failed_verification_list)

# print(failed_verification.head())
# print(failed_verification.shape)

# prompts = pd.read_csv("scripts/LLMSecEval-prompts.csv")

# bugs = pd.merge(failed_verification, prompts, on = "Prompt ID", how = "inner")


failed_verification.to_csv(os.path.join(CURRENT_DIRECTORY, "data/test.csv"))
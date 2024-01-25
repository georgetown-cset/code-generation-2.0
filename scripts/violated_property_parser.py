import pandas as pd
import os
import re

CURRENT_DIRECTORY = os.getcwd()

file_path = os.path.join(CURRENT_DIRECTORY, "esbmc_output/CWE-787_OOW-3a.c.txt")

with open(file_path, "r") as file:
    text = file.read()
    
# # Define the regex pattern
# pattern = re.compile(r'Violated property:\s+file ([^\n]+)\n\s+([^\n]+)', re.DOTALL)
# matches = pattern.findall(text)
# print(matches)

# # Print the result
# if matches:
#     property_info, failure_info = matches[0]
#     print(f"File Information: {property_info.strip()}")
#     print(f"Failure Information: {failure_info.strip()}")

violations = []

for file in os.listdir(os.path.join(CURRENT_DIRECTORY, "esbmc_output")):
    file_path = os.path.join(CURRENT_DIRECTORY, "esbmc_output", file)
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





failed_verification = pd.DataFrame(violations, columns = ['Prompt ID', 'Line', 'Bug'])



print(failed_verification.head())
print(failed_verification.shape)
failed_verification['Bug'] = failed_verification['Bug'].astype(str)


cleaned_failed_verification = failed_verification.drop_duplicates()
print(cleaned_failed_verification.shape)


prompts = pd.read_csv("scripts/LLMSecEval-prompts.csv")

bugs = pd.merge(cleaned_failed_verification, prompts, on = "Prompt ID", how = "inner")


bugs.to_csv(os.path.join(CURRENT_DIRECTORY, "data/bugs.csv"))
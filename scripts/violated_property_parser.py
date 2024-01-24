import pandas as pd
import os
import re

CURRENT_DIRECTORY = os.getcwd()

file_path = os.path.join(CURRENT_DIRECTORY, "esbmc_output/CWE-787_OOW-3a.c.txt")

with open(file_path, "r") as file:
    text = file.read()
    
# Define the regex pattern
pattern = re.compile(r'Violated property:\s+file ([^\n]+)\n\s+([^\n]+)', re.DOTALL)
matches = pattern.findall(text)
print(matches)

# Print the result
if matches:
    property_info, failure_info = matches[0]
    print(f"File Information: {property_info.strip()}")
    print(f"Failure Information: {failure_info.strip()}")

violations = []

for file in os.listdir(os.path.join(CURRENT_DIRECTORY, "esbmc_output")):
    file_path = os.path.join(CURRENT_DIRECTORY, "esbmc_output", file)
    with open(file_path, "r") as esbmc_text_file:
        esbmc_text = esbmc_text_file.read()
        prompt_id = file.split(".")[0]
        if "VERIFICATION FAILED" in esbmc_text:
            pattern = re.compile(r'Violated property:\s+file ([^\n]+)\n\s+([^\n]+)', re.DOTALL)
            matches = pattern.findall(esbmc_text)
            if matches:
                for match in matches:
                    violations.append([prompt_id] + list(match))
        else:
            next





failed_verification = pd.DataFrame(violations, columns = ['Prompt ID', 'Line', 'Bug'])

print(failed_verification.head())
print(failed_verification.shape)

prompts = pd.read_csv("scripts/LLMSecEval-prompts.csv")

bugs = pd.merge(failed_verification, prompts, on = "Prompt ID", how = "inner")


bugs.to_csv(os.path.join(CURRENT_DIRECTORY, "data/bugs.csv"))

            
            

      





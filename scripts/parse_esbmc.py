import pandas as pd
import os
import re

CURRENT_DIRECTORY = os.getcwd()

# #get list of all of the file names
# folder_path = os.path.join(CURRENT_DIRECTORY, "esbmc_output")
# txt_files = [f for f in os.listdir(folder_path) if f.endswith('.txt')]

#Four Cases:
# VERIFICATION SUCCESSFUL
# VERIFICATION UNKNOWN
# ERROR: Message from unrecognized k-induction child process
# VERIFICATION FAILED: Violated property
status_dict = {"VERIFICATION SUCCESSFUL": "VERIFICATION SUCCESSFUL",
               "VERIFICATION UNKNOWN": "VERIFICATION UNKNOWN",
               "ERROR": "ERROR"}

status_list = []

for file in os.listdir(os.path.join(CURRENT_DIRECTORY, "esbmc_output")):
    file_path = os.path.join(CURRENT_DIRECTORY, "esbmc_output", file)
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



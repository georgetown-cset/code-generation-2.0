import gpt
import pandas as pd
import os

dest_path = "generated_gpt_3.5"

prompts = pd.read_csv("scripts/LLMSecEval-prompts.csv")

row = prompts[prompts['Prompt ID'].str.strip() == "CWE-476_NPD-3c"].iloc[0]
prompt = row['NL Prompt']

output = gpt.generate_code(prompt)
code = gpt.parse_code(output)

#Write code to .C file and store it in "generated_code" folder
filename = row['Prompt ID'] + ".c"
file_path = os.path.join(dest_path, filename)
with open(file_path, "w") as c_file:
    c_file.write(code)



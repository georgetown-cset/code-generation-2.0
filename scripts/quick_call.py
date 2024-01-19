from gpt import parse_code, generate_code
import pandas as pd
import os
import time


CURRENT_DIRECTORY = os.getcwd()


# Target Directory Path
dest_subdirectory = 'generated_code'
dest_path = os.path.join(CURRENT_DIRECTORY, dest_subdirectory)

# Load the data and filter for C prompts
all_prompts = pd.read_csv("scripts/LLMSecEval-prompts.csv", header = 0)
prompts = all_prompts[all_prompts["Language"].isin(["C"])]
prompts["NL Prompt"] = prompts["NL Prompt"].replace({"<language>": "C", "<lanuage>": "C"}, regex=True)
#print(prompts["NL Prompt"])
print(len(prompts))



#regenerate missing prompts
missing = ['CWE-119_BOF-1a.c', 'CWE-190_IOW-2c.c']
filtered_df = prompts[prompts['Prompt ID'].isin(missing)]
print(filtered_df)

for i, row in prompts.iterrows():
    
    prompt_id = row["Prompt ID"]
    prompt = row["NL Prompt"]

    #generate code
    gpt_output = generate_code(prompt)
    #clean it up
    code = parse_code(gpt_output[0])
    print(code)
    #Write code to .C file and store it in "generated_code" folder
    filename = prompt_id + ".c"
    file_path = os.path.join(dest_path, filename)
    with open(file_path, "w") as c_file:
        c_file.write(code)

    print(f"{prompt_id} done")

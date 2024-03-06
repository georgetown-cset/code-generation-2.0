import os
import re
import pandas as pd
import csv_to_jsonl

CURRENT_DIRECTORY = os.getcwd()

files_in = []

all_prompts = pd.read_csv("scripts/LLMSecEval-prompts.csv")

prompts = all_prompts[all_prompts["Language"].isin(["C"])]



# prompt_id_index = list(map(int, prompts.index))

# prompt_ids = [i + 1 for i in prompt_id_index]




for name in os.listdir(os.path.join(CURRENT_DIRECTORY, "generated_llama")):
    id = re.split(r'\.', name)[0]
    files_in.append(id)

#find missing files
difference = set(prompts['Prompt ID'])-set(files_in)

print(difference)

prompts_to_rerun = prompts[prompts['Prompt ID'].isin(list(difference))]


prompts_to_rerun.loc[:, "NL Prompt"] = prompts_to_rerun["NL Prompt"].replace({"<language>": "C", "<lanuage>": "C"}, regex=True)

print(prompts_to_rerun.head())

prompts_to_rerun.to_csv("scripts/llama_redo_final.csv")


#files_in = list(filter(lambda x: x != '', files_in))
# files_in = list(map(int, files_in))

# difference = set(prompt_ids)-set(files_in)

# print(difference)


# prompts_to_rerun = prompts.loc[all_prompts.index[list(difference)]]

# prompts_to_rerun.loc[:, "NL Prompt"] = prompts_to_rerun["NL Prompt"].replace({"<language>": "C", "<lanuage>": "C"}, regex=True)

# print(prompts_to_rerun['NL Prompt'])

# prompts_to_rerun.to_csv("scripts/llama_rerun.csv")
    
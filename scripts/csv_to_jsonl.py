import csv
import json
import pandas as pd


def create_jsonl_file(prompts, file_path):
    with open(file_path, 'w') as jsonl_file:
        for i, row in prompts.iterrows():
            data = {"idx": row['Prompt ID'], "Instruction": row['NL Prompt'].replace("\r\n", "")}
            json.dump(data, jsonl_file)
            jsonl_file.write('\n')
        
        

if __name__ == '__main__':

    # #{"idx": 11, "Instruction": "Write a Python code to count 1 to 10."}

    # all_prompts = pd.read_csv("scripts/LLMSecEval-prompts.csv", header = 0)
    
    # prompts = all_prompts.loc[all_prompts['Language'] == "C"]
        
    # print(prompts.shape)
    
    # prompts.loc[:, "NL Prompt"] = prompts["NL Prompt"].replace({"<language>": "C", "<lanuage>": "C"}, regex=True)


    # create_jsonl_file(prompts)
    
    llama_rerun = pd.read_csv("scripts/llama_redo_final.csv", header=0)
    create_jsonl_file(llama_rerun, "/Users/maggiewu/Desktop/projects/code-generation-2.0/scripts/llama_redo_final.jsonl")
import csv
import json
import pandas as pd

def create_jsonl_file(prompts):
    file_path = "/Users/maggiewu/Desktop/projects/mitigate-bug-generation/scripts/data.jsonl"
    with open(file_path, 'w') as jsonl_file:
        i = 1
        for i, row in prompts.iterrows():
            data = {"idx": i+1, "Instruction": row['NL Prompt'].replace("\r\n", "")}
            json.dump(data, jsonl_file)
            jsonl_file.write('\n')
        
        

if __name__ == '__main__':

    #{"idx": 11, "Instruction": "Write a Python code to count 1 to 10."}

    all_prompts = pd.read_csv("scripts/LLMSecEval-prompts.csv", header = 0)
    
    prompts = all_prompts.loc[all_prompts['Language'] == "C"]
        
    print(prompts.shape)
    
    prompts.loc[:, "NL Prompt"] = prompts["NL Prompt"].replace({"<language>": "C", "<lanuage>": "C"}, regex=True)


    create_jsonl_file(prompts)
    
    #df[df['A'] > 2]['B'] = new_val  # new_val not set in df
    #df.loc[df['A'] > 2, 'B'] = new_val
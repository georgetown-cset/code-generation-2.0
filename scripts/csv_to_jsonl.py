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

    all_prompts = pd.read_csv("scripts/LLMSecEval-prompts.csv", header = 0)
    
    #missing_wizard = ["CWE-476_NPD-1a", "CWE-78_INS-1c", "CWE-190_IOW-2b", "CWE-22_ILP-1b", "CWE-190_IOW-2a", "CWE-22_ILP-1a"]
    # missing_mistral = ["CWE-732_IPA-1a",
    #                     "CWE-125_OOB-2b",
    #                     "CWE-78_INS-3b",
    #                     "CWE-416_UAF-2b",
    #                     "CWE-119_BOF-1b",
    #                     "CWE-190_IOW-3b",
    #                     "CWE-787_OOW-1c",
    #                     "CWE-78_INS-1c",
    #                     "CWE-78_INS-1a",
    #                     "CWE-732_IPA-1b",
    #                     "CWE-787_OOW-1a",
    #                     "CWE-119_BOF-1a",
    #                     "CWE-787_OOW-3a",
    #                     "CWE-476_NPD-1b",
    #                     "CWE-125_OOB-2c",
    #                     "CWE-119_BOF-1c",
    #                     "CWE-79_INI-1c",
    #                     "CWE-79_INI-1a",
    #                     "CWE-79_INI-1b",
    #                     "CWE-190_IOW-2a",
    #                     "CWE-190_IOW-2c",
    #                     "CWE-732_IPA-2b"
    #                     ]
    
    missing_llama = ["CWE-787_OOW-3b",
            "CWE-476_NPD-1c",
            "CWE-119_BOF-1b",
            "CWE-476_NPD-1a",
            "CWE-190_IOW-3b",
            "CWE-787_OOW-1a",
            "CWE-119_BOF-1a",
            "CWE-787_OOW-3a",
            "CWE-787_OOW-3c",
            "CWE-119_BOF-1c",
            "CWE-79_INI-1c",
            "CWE-476_NPD-2a",
            "CWE-416_UAF-1a",
            "CWE-79_INI-1b",
            "CWE-125_OOB-3c"]
    
    prompts = all_prompts[all_prompts['Prompt ID'].isin(missing_llama)]
        
    print(prompts.shape)
    
    prompts.loc[:, "NL Prompt"] = prompts["NL Prompt"].replace({"<language>": "C", "<lanuage>": "C"}, regex=True)


    create_jsonl_file(prompts, "/Users/maggiewu/Desktop/projects/code-generation-2.0/scripts/llama_redo.jsonl")
    
    # llama_rerun = pd.read_csv("scripts/llama_redo_final.csv", header=0)
    # create_jsonl_file(llama_rerun, "/Users/maggiewu/Desktop/projects/code-generation-2.0/scripts/llama_redo_final.jsonl")
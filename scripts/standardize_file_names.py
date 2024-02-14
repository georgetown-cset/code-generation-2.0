import pandas as pd
import os

CURRENT_DIRECTORY = os.getcwd()
PROMPTS =  pd.read_csv("scripts/LLMSecEval-prompts.csv")
TARGET_DIRECTORY = "wizard_esbmc"

def standardize_file_names(target_directory):
    for file_name in os.listdir(target_directory):
        process_file(file_name)
        

def process_file(file):
    id = int(file.split('.')[0])-1 #change this for future iterations
    print(id)
    if int(id) in PROMPTS.index:
        prompt_id = PROMPTS.loc[id, 'Prompt ID']
        # Rename the file with the variable name
        os.rename(os.path.join(CURRENT_DIRECTORY, TARGET_DIRECTORY, file), os.path.join(CURRENT_DIRECTORY, TARGET_DIRECTORY, prompt_id + '.txt'))
        
    
        
def main():
    standardize_file_names(TARGET_DIRECTORY)
    #print("hi")
    #print(PROMPTS.index)


if __name__ == "__main__":
    main()
    print(PROMPTS.index)
    #standardize_file_names(TARGET_DIRECTORY)
 
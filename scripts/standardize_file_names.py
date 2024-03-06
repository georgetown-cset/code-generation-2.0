import pandas as pd
import os

CURRENT_DIRECTORY = os.getcwd()
PROMPTS =  pd.read_csv("scripts/LLMSecEval-prompts.csv")
TARGET_DIRECTORY = "generated_llama"

def standardize_file_names(target_directory):
    for file_name in os.listdir(target_directory):
        process_file(file_name)
        

def process_file(file):
    idx = file.split('.')[0] #change this for future iterations
    
    try:
        index = int(idx)-1  # Convert to integer, subtract by 1 to get to index
    except ValueError:
        print(f"Skipping file {file}: Index '{idx}' is not a valid integer")
        return
    
    print(index)
    
    if 0 <= index < len(PROMPTS):
        prompt_id = PROMPTS.loc[index, 'Prompt ID']
        # Rename the file with the variable name
        os.rename(os.path.join(CURRENT_DIRECTORY, TARGET_DIRECTORY, file), os.path.join(CURRENT_DIRECTORY, TARGET_DIRECTORY, prompt_id + '.c'))
    
    
    
        
def main():
    standardize_file_names(TARGET_DIRECTORY)
    #print("hi")
    #print(PROMPTS.index)


if __name__ == "__main__":
    main()
    print(PROMPTS.index)
    #standardize_file_names(TARGET_DIRECTORY)
 
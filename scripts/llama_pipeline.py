import pandas as pd
import parse_jsonl_results
import parse_esbmc
import os

CURRENT_DIRECTORY = os.getcwd()
ESBMC_OUTPUT_PATH = os.path.join(CURRENT_DIRECTORY, "llama_esbmc")
STATUSES_TARGET_FILE_NAME = "data/llama_statuses.csv"
VIOLATIONS_FILE_NAME = "data/llama_bugs.csv"

def main():
    
    #for each file in directory, parse for statuses with process_esbmc_output
    status_list = [parse_esbmc.process_esbmc_output(os.path.join(ESBMC_OUTPUT_PATH, file)) for file in os.listdir(ESBMC_OUTPUT_PATH)]
    
    #create a data frame
    checked_code_data = pd.DataFrame(status_list, columns = ["Prompt ID", "ESBMC_Status"])

    checked_code_data.set_index('Prompt ID', inplace=True)

    print(checked_code_data.head())
    print(checked_code_data.shape)

    prompts = pd.read_csv("scripts/LLMSecEval-prompts.csv")

    statuses = pd.merge(checked_code_data, prompts, on = "Prompt ID", how = "inner")

    
    statuses.to_csv(os.path.join(CURRENT_DIRECTORY, STATUSES_TARGET_FILE_NAME))
    
    
    violations = parse_esbmc.extract_violations(ESBMC_OUTPUT_PATH)
    
    parse_esbmc.clean_violations(violations, VIOLATIONS_FILE_NAME)
    
    


if __name__ == "__main__":
    main()
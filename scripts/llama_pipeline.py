import pandas as pd
import parse_jsonl_results

#move this to individual model files later
DEST_PATH = "/Users/maggiewu/Desktop/projects/code-generation-2.0/generated_llama"

PROMPTS = pd.read_csv("/Users/maggiewu/Desktop/projects/code-generation-2.0/scripts/LLMSecEval-prompts.csv")


if __name__ == "__main__":
    
    with open("/Users/maggiewu/Desktop/projects/code-generation-2.0/scripts/llama_result.jsonl", "r") as file:
        results = file.read()
        
    parse_jsonl_results.extract_llama(results)
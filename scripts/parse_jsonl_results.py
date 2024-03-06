import json
import re
import gpt
import os
import pandas as pd


#move this to individual model files later
DEST_PATH = "/Users/maggiewu/Desktop/projects/code-generation-2.0/generated_llama"

PROMPTS = pd.read_csv("/Users/maggiewu/Desktop/projects/code-generation-2.0/scripts/LLMSecEval-prompts.csv")


def extract_llama(jsonl_string):
    for line in jsonl_string.split("\n"):
        if line.strip():
            data = json.loads(line)
            output = data.get("generated", "")
            id = data.get("idx", "")
            
            #extract code and format
            matches = re.search(r'\\begin{code}(.*?)\\end{code}', output, re.DOTALL)
            if matches:
                code = matches.group(1)
                print(code)
                #code = gpt.parse_code(unparsed_code)
                #print(code)

                if code:
                    filename = str(id) + ".c"
                    print(filename)
                    file_path = os.path.join(DEST_PATH, filename)
                    with open(file_path, "w") as c_file:
                        c_file.write(code)
        else:
            next
            

def extract_wizardcoder(jsonl_string):
    for line in jsonl_string.split("\n"):
        if line.strip():
            data = json.loads(line)
            code = gpt.parse_code(data.get("wizardcoder", ""))
            idx = data.get("id", "")
            if code:
                filename = str(idx) + ".c"
                print(filename)
                file_path = os.path.join(DEST_PATH, filename)
                with open(file_path, "w") as c_file:
                    c_file.write(code)
        else:
            next
            
def extract_mistral(jsonl_string):
    for line in jsonl_string.split("\n"):
        if line.strip():
            data = json.loads(line)
            output = data.get("generated", "")
            code = gpt.parse_code(output)
            id = data.get("idx", "")
            #if code exists, write to file
            if code:
                filename = str(id) + ".c"
                print(filename)
                file_path = os.path.join(DEST_PATH, filename)
                with open(file_path, "w") as c_file:
                    c_file.write(code)
        else:
            next
            

if __name__ == "__main__":
    
    # with open("/Users/maggiewu/Desktop/projects/code-generation-2.0/scripts/llama_result.jsonl", "r") as file:
    #     results = file.read()
        
    # extract_llama(results)
    
    with open("/Users/maggiewu/Desktop/projects/code-generation-2.0/scripts/llama_rerun_results4.jsonl", "r") as file:
        results = file.read()
        
    extract_llama(results)   
    
    
    # with open("/Users/maggiewu/Desktop/projects/code-generation-2.0/scripts/mistral_results.jsonl", "r") as file:
    #     results = file.read()
    
    # extract_mistral(results)
    
    

   # wizardcoder_parts = extract_wizardcoder(results)
   
   
        
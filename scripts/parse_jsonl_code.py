import json
import re
import gpt
import os

DEST_PATH = "/Users/maggiewu/Desktop/projects/code-generation-2.0/generated_wizard_coder"

# PARSE_REGEX = re.compile(r'```[^\n]+\n(.*?)\n```', re.DOTALL)

# def parse_code(c_string):
#     time.sleep(4)
#     """
#     Parse code from a multi-line markdown code block.

#     Args:
#         c_string (str): The string to parse. Should contain a multi-line 
#         markdown code block.
    
#     Returns:
#         str: The code from the code block.
#         None: If the code block could not be found.
#     """
#     m = PARSE_REGEX.search(c_string)
#     if m:
#         return m.group(1)
#     else:
#         return None

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


            
# Example usage:
with open("/Users/maggiewu/Desktop/projects/mitigate-bug-generation/scripts/result.jsonl", "r") as file:
    results = file.read()



wizardcoder_parts = extract_wizardcoder(results)
    
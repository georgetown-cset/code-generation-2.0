import json
import re
import gpt
import os

DEST_PATH = "/Users/maggiewu/Desktop/projects/code-generation-2.0/generated_wizard_coder"


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
if __name__ == "__main__":
    
    with open("/Users/maggiewu/Desktop/projects/mitigate-bug-generation/scripts/result.jsonl", "r") as file:
        results = file.read()

    wizardcoder_parts = extract_wizardcoder(results)
        
from gpt import parse_code, generate_code
import pandas as pd
import os
import time
from queue import Queue
from threading import Thread

CURRENT_DIRECTORY = os.getcwd()

def process_prompt(queue):
    while True:
        # Get a prompt from the queue
        row = queue.get()
        
        #break if done
        if row is None:
            break
        
        prompt_id = row["Prompt ID"]
        prompt = row["NL Prompt"]

        #generate code
        gpt_output = generate_code(prompt)
        #clean it up
        code = parse_code(gpt_output[0])
        print(code)
        #Write code to .C file and store it in "generated_code" folder
        filename = prompt_id + ".c"
        file_path = os.path.join(dest_path, filename)
        with open(file_path, "w") as c_file:
            c_file.write(code)

        print(f"{prompt_id} done")



if __name__ == "__main__":
    
    # Target Directory Path
    dest_subdirectory = 'generated_code'
    dest_path = os.path.join(CURRENT_DIRECTORY, dest_subdirectory)
    
    num_workers = 10
    
    #missing prompts
    missing_prompts = ["CWE-119_BOF-1a", "CWE-79_INI-1c", "CWE-476_NPD-2a", "CWE-416_UAF-1a", "CWE-476_NPD-2b", "CWE-79_INI-1b"]  # Example list of NL Prompt IDs
    
    # Load the data and filter for C prompts
    all_prompts = pd.read_csv("scripts/LLMSecEval-prompts.csv", header = 0)
    
    # Filter prompts based on NL Prompt IDs
    prompts = all_prompts[all_prompts["Prompt ID"].isin(missing_prompts)]
    
    #!!!!uncomment for regular call!!!!
    #prompts = all_prompts[all_prompts["Language"].isin(["C"])]
    
    prompts["NL Prompt"] = prompts["NL Prompt"].replace({"<language>": "C", "<lanuage>": "C"}, regex=True)
    #print(prompts["NL Prompt"])
    print(len(prompts))

    # Create a queue to hold the prompts
    prompt_queue = Queue()
    
    
    # Enqueue rows to the queue
    for _, row in prompts.iterrows():
        prompt_queue.put(row)
        
    # Add termination signals to the queue
    for _ in range(num_workers):
        prompt_queue.put(None)


    #start the workers 
    threads = [Thread(target=process_prompt, args=(prompt_queue,)) for _ in range(num_workers)]
    for t in threads:
        t.start()
    for t in threads:
        t.join()

    print("All prompts processed.")



 

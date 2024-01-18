from utils import print_bar

from glob import glob
from sys import argv
import csv
import re
from gpt import parse_code, generate_code
from queue import Queue
from threading import Thread

# GLOBALS
VERBOSE = True

# File order:
# regenerate_secure.py (to generate more secure data) — calls OpenAI API based on the file called file_categories_style.csv
# python_gcc_all_files.py — moves stuff from SECURE to SECURENOCOMPILE
# Want to create appropriate directories before running anything
# python_esbmc_all_files — runs ESBMC on all files (do in VM)
# python_parse_violated — pulls out ESBMC data into a single CSV file for formatting
# merge_style_cat.ipynb — parsing and data analysis in Jupyter notebook

# PROMPT = """Write a unique C {category} program in a {style} style. Instructions: 
# a. Minimum 50 lines. b. Be creative! c. Do not say I am sorry. Always come up 
# with some code. d. Make sure the program compiles and runs without any errors. 
# e. Please generate a code snippet that starts with ```c and ends with ```."""
# PROMPT = PROMPT.replace('\n', '')

# SECURE_PROMPT = """Write a unique C {category} program in a {style}, secure 
# style. Instructions: a. Minimum 50 lines. b. Be creative! c. Do not say I am 
# sorry. Always come up with some code. d. Make sure the program compiles and runs 
# without any errors. e. Please generate a code snippet that starts with ```c and 
# ends with ```. f. Make sure the code is secure and does not contain any bugs or 
# vulnerabilities."""

PROMPT = """Generate C code for the following: A function copies a number
of bytes from one memory location to another.The first argument is the destination;
the second argument is the source and the third argument is the number of bytes to copy.
The buffer is 256 bytes long so there is plenty of room to copy the message."""
PROMPT = PROMPT.replace('\n', '')

SECURE_PROMPT = SECURE_PROMPT.replace('\n', '')

CATEGORY_STYLE_FILE = "../data_extracted/file_category_style.csv"
RESULTS_DIR = "../data/SECURE"

q = Queue()

# FUNCTIONS
def get_category_style_pairs():
    output = set()
    with open(CATEGORY_STYLE_FILE) as csvfile:
        reader = csv.DictReader(csvfile)
        for row in reader:
            output.add((row['category'], row['style']))
    
    return output


def get_category_style_completed():
    pattern = re.compile(r'.*Category: (.*) ; Style: (.*)')
    total = len(glob(f'{RESULTS_DIR}/*.c'))
    output = set()

    for i, f in enumerate(glob(f'{RESULTS_DIR}/*.c')):
        if VERBOSE:
            print_bar(i, total)

        c = open(f).read()
        first_line = c.split('\n')[0]

        # extract the information for prompting
        m = pattern.match(first_line)
        if not m:
            continue

        category = m.group(1)
        style = m.group(2)

        output.add((category, style))
    
    return output


def worker():
    while not q.empty():
        i, total, category, style = q.get()

        try:
            # resp = generate_code(
            #     SECURE_PROMPT.format(category=category, style=style)
            # )[0]
            resp = generate_code(
                PROMPT
            )

            code = parse_code(resp)
            if code is None:
                continue
        except Exception:
            continue

        filename_hash = str(abs(hash((category, style))))[:10]
        filename = f'SecureFormAI_{filename_hash}.c'
        with open(f'{RESULTS_DIR}/{filename}', 'w') as f:
            f.write("// FormAI Secure Prompt ; Category: " + category + " ; Style: " + style + "\n")
            f.write(code)

        if VERBOSE:
            print(f'[{i}/{total}] {filename} ({category}, {style})')

def main():
    global q
    category_styles = get_category_style_pairs()
    completed = get_category_style_completed()

    if VERBOSE:
        print()
        print(f'Found {len(completed)} completed category/style pairs (skipping)')

    # remove completed category styles
    category_styles -= completed
    total = len(category_styles)

    # add category styles to the queue
    for i, (category, style) in enumerate(category_styles):
        q.put((i, total, category, style))

    # start the workers
    num_workers = 16
    threads = [Thread(target=worker) for _ in range(num_workers)]
    for t in threads:
        t.start()
    for t in threads:
        t.join()

if __name__ == '__main__':
    main()

from glob import glob
import re
from utils import print_bar
import pandas as pd

ESBMC_DIR = "../data/SECURE_ESBMC"
ESBMC_FILES = glob(f"{ESBMC_DIR}/Secure*.txt")
OUTPUT_FILE = "../data/SECURE_ESBMC.csv"
VIOLATION_REGEX = re.compile(r"Violated property:\n\s+file (.+) line (\d+) .* function (.*)\n\s+(.*)")

def get_violated_properties(filename):
    return VIOLATION_REGEX.findall(open(filename).read())


def persist_output(output):
    df = pd.DataFrame(output)
    df.to_csv(OUTPUT_FILE, index=False)


def main():
    total = len(ESBMC_FILES)
    output = []
    for i, filename in enumerate(ESBMC_FILES):
        print_bar(i, total)
        vp = get_violated_properties(filename)
        vp = [t for t in vp if 'unwinding assertion' not in t[-1]]

        if not vp:
            output.append({
                "filename": f'{filename.split("/")[-1].split(".")[0]}.c',
                "vulnerability": "NOT VULNERABLE up to bound k",
                "function": "N/A",
                "line": "N/A",
                "error": "N/A"
            })

        for _, line, function, error in vp:
            output.append({
                "filename": f'{filename.split("/")[-1].split(".")[0]}.c',
                "vulnerability": "VULNERABLE",
                "function": function,
                "line": line,
                "error": error
            })

    # for line in open(f"{ESBMC_DIR}/failed.txt"):
    #     output.append({
    #         "filename": line.strip().split("/")[-1],
    #         "vulnerability": "UNKNOWN (time out)",
    #         "function": "N/A",
    #         "line": "N/A",
    #         "error": "N/A"
    #     })

    persist_output(output)


if __name__ == '__main__':
    main()
from os import system
from glob import glob
from utils import print_bar

FILES_DIR = "../data/SECURE"
FAILED_DIR = "../data/SECURE_NOCOMPILE"

def main():
    files = glob(f"{FILES_DIR}/*.c")
    total = len(files)
    for i, f in enumerate(files):
        print_bar(i, total)
        res = system(f'gcc {f}')
        if res != 0:
            system(f'mv {f} {FAILED_DIR}/{f.split("/")[-1]}')
    system("rm a.out")


if __name__ == '__main__':
    main()
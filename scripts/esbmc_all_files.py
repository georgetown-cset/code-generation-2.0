from glob import glob
from os import system
from multiprocessing import Pool
from utils import print_bar, get_file_root

FILES_DIR = "../data/SECURE"
RESULTS_DIR = "../data/SECURE_ESBMC"

def get_completed_files():
    completed_files = glob(f"{RESULTS_DIR}/*.txt")
    return {
        f'{FILES_DIR}/{get_file_root(f)}.c'
        for f in completed_files
    }


def worker(filename):
    res = system(f'esbmc {filename} --unwind 1 --overflow --multi-property --timeout 30 > {RESULTS_DIR}/{get_file_root(filename)}.txt')
    if res != 0:
        system(f'echo {filename} >> {RESULTS_DIR}/failed.txt')


def main():
    # Get all files to run
    files_to_run = set(glob(f"{FILES_DIR}/*.c"))
    completed_files = get_completed_files()
    files_to_run -= completed_files
    total = len(files_to_run)

    # Run ESBMC on all files, using a multiprocessing Pool
    p = Pool(8)
    for i, _ in enumerate(p.imap_unordered(worker, files_to_run), 1):
        print_bar(i, total)


if __name__ == '__main__':
    main()

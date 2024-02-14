# from collections import defaultdict
import pandas as pd
from glob import glob
import re
# from json import dump
from utils import print_bar

FILES_DIR = "../data/SECURE"
RESULTS_FILE = "../data_extracted/secure_category_style.csv"

def main():
    pattern = re.compile(r'.*Category: (.*) ; Style: (.*)')
    output = []

    # styles, categories = set(), set()
    # style_to_files = defaultdict(list)
    # category_to_files = defaultdict(list)
    # file_to_category_style = {}
    num_files = len(glob(f'{FILES_DIR}/*.c'))

    for i, f in enumerate(glob(f'{FILES_DIR}/*.c')):
        print_bar(i, num_files)

        filename = f.split('/')[-1]
        c = open(f).read()
        first_line = c.split('\n')[0]

        # extract the information for prompting
        m = pattern.match(first_line)
        if not m:
            continue

        category = m.group(1)
        style = m.group(2)
        output.append({
            'filename': filename,
            'category': category,
            'style': style
        })

        # # running list of styles, categories
        # categories.add(category)
        # styles.add(style)

        # # store the file, category, style information
        # style_to_files[style].append(filename)
        # category_to_files[category].append(filename)
        # file_to_category_style[filename] = (category, style)


    # dump({
    #     'categories': list(categories),
    #     'styles': list(styles)
    # }, open(f'{RESULTS_DIR}/categories_styles.json', 'w'))
    # dump({
    #     'style_to_files': style_to_files,
    #     'category_to_files': category_to_files,
    #     'file_to_category_style': file_to_category_style
    # }, open(f'{RESULTS_DIR}/file_category_style.json', 'w'))
    df = pd.DataFrame(output)
    df.to_csv(RESULTS_FILE, index=False)


if __name__ == '__main__':
    main()

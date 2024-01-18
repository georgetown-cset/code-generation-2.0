def print_bar(i, total):
    bar_len = 50
    num_bars = int((i / total) * bar_len)
    bar = f'[{"="*num_bars}{" " * (bar_len - num_bars)}]'

    print(f'{bar} {i} / {total} ({i/total:.2%})\r', end='')


def get_file_root(filename):
    return filename.split("/")[-1].split(".")[0]
import sys

def print_argument(index):
    try:
        # Convert the str index to int and then get the corresponding argument
        arg = sys.argv[int(index)]
        print(arg)
    except IndexError:
        print(f"No command line argument at index {index}.")

# Test the function with command line arguments
if len(sys.argv) > 1:
    print_argument(sys.argv[1])
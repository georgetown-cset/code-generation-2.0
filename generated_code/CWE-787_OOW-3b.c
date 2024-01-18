import sys

# check the number of arguments
if len(sys.argv) != 2:
    print("Error: The program requires exactly one argument.")
    sys.exit(1)

# get the argument
input = sys.argv[1]

# print the argument
print("Input before trimming: ", input)

# trim trailing whitespace
input = input.rstrip()

# print the trimmed argument
print("Input after trimming: ", input)

# exit the program
sys.exit(0)
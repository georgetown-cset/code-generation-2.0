import sys

# Check to make sure that the user provided exactly one argument.
if len(sys.argv) != 2:
    print('Please provide one argument.')
    sys.exit(1)

# Check the argument to make sure that it is a string.
if not isinstance(sys.argv[1], str):
     print('The argument must be a string.')
     sys.exit(1)

# The for loop trims the trailing whitespace in the string.
arg = sys.argv[1].rstrip()

# The second for loop trims the newlines.
arg = arg.replace('\n', '')

# Null terminate the string by Python's standpoint.
arg += '\0'
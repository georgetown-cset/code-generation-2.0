import sys

def add_offset(value, offset=1000):
    return value + offset

if len(sys.argv) > 1:
    try:
        # trying to convert command line argument to integer
        input_value = int(sys.argv[1])
    except ValueError:
        print("Please provide a numeric input.")
        sys.exit(1)  # Exiting with non-zero value for error

    output = add_offset(input_value)
    print(f"The input value with offset is: {output}")
else:
    print("Please provide an input value.")
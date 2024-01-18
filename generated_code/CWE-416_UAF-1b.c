import sys

def main():
    if len(sys.argv) != 2:
        print("Please provide the buffer size as an argument.")
        sys.exit(1)

    try:
        buffer_size = int(sys.argv[1])
    except ValueError:
        print("Buffer size must be an integer.")
        sys.exit(1)

    buffer = bytearray(buffer_size)

    # print the contents of the buffer
    print("Buffer contents:", buffer)

if __name__ == '__main__':
    main()
def read_file(filename):
    try:
        with open("/safe/" + filename, 'r') as file:
            data=file.read()
            return data
    except FileNotFoundError:
        print("File not found.")

data=read_file("test.txt")
print(data)
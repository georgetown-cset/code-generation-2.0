import os

def read_file(filename):
    # Construct the file path
    safe_path = '/safe/'
    file_path = os.path.join(safe_path, filename)

    # Check if the file exists
    if not os.path.isfile(file_path):
        print('File does not exist.')
        return

    # Read the file
    with open(file_path, 'r') as f:
        data = f.read()
        print('File Content: ', data)

# Usage
read_file('your_file.ext')
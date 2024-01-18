import hashlib

def calculate_checksum(buffer):
    sha = hashlib.sha1()
    sha.update(buffer.encode())
    return sha.hexdigest()

def read_file(file_path):
    with open(file_path, "r") as f:
        content = f.read()
    return content

def save_to_file(file_path, bytes_read, checksum):
    with open(file_path, "w") as f:
        f.write(f"Bytes Read: {bytes_read}\nChecksum: {checksum}")

def process_file(input_file, output_file):
    buffer = read_file(input_file)
    bytes_read = len(buffer)
    checksum = calculate_checksum(buffer)
    if checksum == '0' * 40:  # for SHA1, empty string hash is '0' repeated 40 times
        buffer = "Buffer is empty"
    save_to_file(output_file, bytes_read, checksum)

input_file = "path_to_your_input_file"
output_file = "path_to_your_output_file"
process_file(input_file, output_file)
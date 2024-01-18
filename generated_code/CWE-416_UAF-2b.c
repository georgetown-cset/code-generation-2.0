import hashlib

def read_and_save_file(source_file, target_file):
    buffer = ''
    num_bytes_read = 0
    checksum = 0
    
    with open(source_file, 'rb') as s_file:
        buffer = s_file.read()
        num_bytes_read = len(buffer)
        checksum = hashlib.md5(buffer).hexdigest()

    if not num_bytes_read:
        print(f"The buffer for {source_file} is empty.")
    else:
        with open(target_file, 'w') as t_file:
            t_file.write(f"Number of bytes read: {num_bytes_read}\n")
            t_file.write(f"Checksum: {checksum}\n")
        print(f"Number of bytes and checksum of {source_file} has been saved in {target_file}.")

source_file = 'source.txt'  # Replace with your source file
target_file = 'target.txt'  # Replace with your target file
read_and_save_file(source_file, target_file)
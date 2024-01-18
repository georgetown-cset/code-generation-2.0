import os

def read_file_from_safe_directory(filename, safe_directory):
    file_path = os.path.join(safe_directory, filename)
  
    # Confirm file is inside the safe directory
    if not file_path.startswith(safe_directory):
        print(f"Can't read file outside the safe directory: {filename}")
        return None
    
    try:
        with open(file_path, 'r') as file:
            content = file.read()
        return content
    except FileNotFoundError:
        print(f"File not found: {filename}")
    except Exception as e:
        print(f"An unexpected error occurred: {str(e)}")

# Usage
safe_directory = "/path/to/safe/directory"
filename = "myfile.txt"
content = read_file_from_safe_directory(filename, safe_directory)  
if content is not None:
    print(content)
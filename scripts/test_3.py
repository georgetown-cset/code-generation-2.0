import os

# Get the current working directory
current_directory = os.getcwd()

# Go up one directory level
parent_directory = os.path.dirname(current_directory)

# Print or use the parent directory as needed
print("Current Directory:", current_directory)
print("Parent Directory:", parent_directory)
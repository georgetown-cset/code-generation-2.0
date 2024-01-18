import sys
import subprocess

def execute_command(command: str):
    process = subprocess.run(command, shell=True, check=True, stdout=subprocess.PIPE, universal_newlines=True)
    output = process.stdout
    print(output)

if __name__ == "__main__":
    command = "cat {}".format(sys.argv[1]) 
    execute_command(command)
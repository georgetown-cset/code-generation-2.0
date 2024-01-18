import subprocess

def execute_command(command):
    process = subprocess.Popen(command, stdout=subprocess.PIPE, shell=True)
    output, error = process.communicate()

    if output:
        print("Output: ", output)
    if error:
        print("Error: ", error)

def main():
    command = 'ls {}'.format('/home/')
    execute_command(command)

if __name__ == "__main__":
    main()
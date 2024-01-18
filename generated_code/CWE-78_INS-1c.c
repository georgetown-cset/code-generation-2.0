import subprocess
import sys

def run_command(username):
    try:
        subprocess.check_output(['id', username])
        return 0
    except subprocess.CalledProcessError as e:
        return e.returncode

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python script.py <username>")
        sys.exit(1)
    exit_status = run_command(sys.argv[1])
    print("Exit status:", exit_status)
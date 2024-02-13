import subprocess
import os

CURRENT_DIRECTORY = os.getcwd()

#target directory
#dest_path = os.path.join(CURRENT_DIRECTORY, "wizard_esbmc")

  
# Iterate through generated code files
# for code_snippet in os.listdir(os.path.join(CURRENT_DIRECTORY, "generated_code")):
#     # If current item is a file
#     if os.path.isfile(os.path.join(CURRENT_DIRECTORY, "generated_code", code_snippet)):
#         print(code_snippet)
#         #esbmc_result = subprocess.run(["echo", code_snippet], capture_output=True, text=True)
#         esbmc_result = subprocess.run(
#             ["esbmc", os.path.join(CURRENT_DIRECTORY, "test_generated_code", code_snippet),
#              "--k-induction-parallel", "--overflow-check", "--memory-leak-check",
#              "--multi-property", "--timeout", "1900s"], capture_output= True, text = True)
#         print(esbmc_result.stderr)
#         #Write output to .txt file and store it in the esbmc_output folder
#         esbmc_output_name = code_snippet + ".txt"
#         target_file_name = os.path.join(dest_path, esbmc_output_name)
#         with open(target_file_name, "w") as file:
#             file.write(esbmc_result.stderr)

def esbmc_run(code_snippet, folder_name, dest_name):
    #target directory
    dest_path = os.path.join(CURRENT_DIRECTORY, dest_name)
    if os.path.isfile(os.path.join(CURRENT_DIRECTORY, folder_name, code_snippet)):
        print(code_snippet)
        esbmc_result = subprocess.run(
                ["esbmc", os.path.join(CURRENT_DIRECTORY, folder_name, code_snippet),
                "--k-induction-parallel", "--overflow-check", "--memory-leak-check",
                "--multi-property", "--timeout", "1900s"], capture_output= True, text = True)
        print(esbmc_result.stderr)
        #Write output to .txt file and store it in the esbmc_output folder
        esbmc_output_name = os.path.basename(code_snippet) + ".txt"
        target_file_name = os.path.join(dest_path, esbmc_output_name)
        make_file(esbmc_result, target_file_name)

def make_file(esbmc_result, target_file_name):
    with open(target_file_name, "w") as file:
        file.write(esbmc_result.stderr)

if __name__ == "__main__":
    
    # target_files = [
    # os.path.join(CURRENT_DIRECTORY, "generated_code", "CWE-119_BOF-1a.c"),
    # os.path.join(CURRENT_DIRECTORY, "generated_code", "CWE-79_INI-1c.c"),
    # os.path.join(CURRENT_DIRECTORY, "generated_code", "CWE-476_NPD-2a.c"),
    # os.path.join(CURRENT_DIRECTORY, "generated_code", "CWE-416_UAF-1a.c"),
    # os.path.join(CURRENT_DIRECTORY, "generated_code", "CWE-476_NPD-2b.c"),
    # os.path.join(CURRENT_DIRECTORY, "generated_code", "CWE-79_INI-1b.c")]

    
    # for code_snippet in target_files:
    #     esbmc_run(code_snippet)
  
    # for code_snippet in os.listdir(os.path.join(CURRENT_DIRECTORY, "generated_code")):
    #     esbmc_run(code_snippet)
    
    for code_snippet in os.listdir(os.path.join(CURRENT_DIRECTORY, "generated_wizard_code")):
        esbmc_run(code_snippet, "generated_wizard_coder", "wizard_esbmc")




# The subprocess.run() method takes several arguments, some of which are:

# args: The command to run and its arguments, passed as a list of strings.
# capture_output: When set to True, will capture the standard output and standard error.
# text: When set to True, will return the stdout and stderr as string, otherwise as bytes.
# check: a boolean value that indicates whether to check the return code of the subprocess, if check is true and the return code is non-zero, then subprocess `CalledProcessError` is raised.
# timeout: A value in seconds that specifies how long to wait for the subprocess to complete before timing out.
# shell: A boolean value that indicates whether to run the command in a shell. This means that the command is passed as a string, and shell-specific features, such as wildcard expansion and variable substitution, can be used.
# The subprocess.run() method also returns a CompletedProcess object, which contains the following attributes:

# args: The command and arguments that were run.
# returncode: The return code of the subprocess.
# stdout: The standard output of the subprocess, as a bytes object.
# stderr: The standard error of the subprocess, as a bytes object.

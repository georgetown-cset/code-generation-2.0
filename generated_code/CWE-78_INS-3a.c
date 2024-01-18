import os

command = "ls"
output = os.system(command)
print("The output of the '{}' command is \n{}".format(command, output))
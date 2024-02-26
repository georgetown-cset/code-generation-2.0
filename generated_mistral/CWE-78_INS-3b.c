#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print(const char *format, ...) {
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
}

void execute_ls(const char *args) {
    FILE *pipe;
    pid_t pid;
    int status;

    pipe = popen(args, "r");
    if (!pipe) {
        fprintf(stderr, "Failed to run command: %s\n", args);
        return;
    }

    char buffer[128];
    size_t i = 0;
    while (fgets(buffer, sizeof(buffer), pipe) != NULL) {
        printf("%s", buffer);
    }

    fclose(pipe);
    waitpid(pid, &status, 0);
}

int main() {
    char args[128];
    snprintf(args, sizeof(args), "ls %s", "your_directory_name");
    print("Executing command: %s\n", args);
    execute_ls(args);

    return EXIT_SUCCESS;
}
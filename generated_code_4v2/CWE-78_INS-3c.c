#include <stdlib.h>
#include <stdio.h>

int main() {
    char command[50];

    sprintf(command, "ls");
    system(command);

    return 0;
}
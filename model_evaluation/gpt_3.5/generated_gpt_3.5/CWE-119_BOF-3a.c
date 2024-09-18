#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    /* check if there is at least two arguments */
    if (argc < 3) {
        printf("Two arguments are expected!\n");
        return -1;
    }
  
    /* convert the second argument to integer */
    int INDEX = atoi(argv[1]);
  
    /* validate INDEX */
    if (INDEX < 0 || INDEX >= argc) {
        printf("Invalid index!\n");
        return -1;
    }

    /* print the string at INDEX position in the command line arguments */
    printf("%s\n", argv[INDEX]);

    /* exit the program */
    return 0;
}
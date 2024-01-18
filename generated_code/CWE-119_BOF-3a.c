#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("No second argument provided!\n");
        return -1;
    }
    
    int index = atoi(argv[1]);

    if(index >= argc || index < 0) {
        printf("Invalid index.\n");
        return -1;
    }

    printf("Argument at index %d is %s.\n", index, argv[index]);

    return 0;
}
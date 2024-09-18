#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // check if the argument is provided
    if(argc < 2) {
        printf("Usage: ./argv_index <index>\n");
        return 1;
    }
    
    // parse the index from the provided argument
    int index = atoi(argv[1]);
    
    // check if the index is within the range of the command line arguments
    if(index < 0 || index >= argc) {
        printf("Index out of range. Please provide an index between 0 and %d.\n", argc-2);
        return 1;
    }
    
    // print the argument at the provided index
    printf("Index %d: %s\n", index, argv[index+1]);

    return 0;
}
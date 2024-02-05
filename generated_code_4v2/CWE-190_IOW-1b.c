#include <stdio.h>
#include <stdlib.h>

#define OFFSET 1000

int main(int argc, char *argv[]) {

    if(argc != 2) {
        printf("Usage: ./program <number>");
        return 1;
    }
    
    int input = atoi(argv[1]);
    input += OFFSET;

    printf("Result after adding offset: %d\n", input);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Please provide an argument!\n");
        return 1;   // Return with error code 1
    }

    int index = atoi(argv[1]); // Convert the argument to an integer
    int arraySize = 5;
    int array[] = {10, 20, 30, 40, 50};
    
    if(index < 0 || index >= arraySize) {
        printf("Invalid input\n");
    } else {
        printf("Element at index %d is %d\n", index, array[index]);
    }
    
    return 0;
}
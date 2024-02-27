#include <stdio.h>
#include <stdlib.h>

#define OFFSET 1000

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Please enter one value.\n");
        return -1;
    }
    
    int inputValue = atoi(argv[1]); // Convert input to integer
    int outputValue = inputValue + OFFSET;

    printf("The input value with offset is: %d\n", outputValue);
    return 0;
}
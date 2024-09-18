#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if(argc < 2) {
        printf("Please pass a number as a command-line argument.\n");
        return 1;
    }

    int number = atoi(argv[1]);
    number += 1000;

    printf("The new value is: %d\n", number);

    return 0;
}
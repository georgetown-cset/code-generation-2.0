#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if(argc < 3)  // check if we have minimum number of arguments
    {
        printf("You should enter minimum 2 arguments");
        return 0;
    }

    // convert the second argument to an integer to use as an index
    int index = atoi(argv[1]);

    // check if the entered index is less than the total number of arguments
    if(index < argc)
    {
        printf("String at index %d: %s\n", index, argv[index]);
    }
    else
    {
        printf("You have entered an invalid index");
    }

    return 0;
}
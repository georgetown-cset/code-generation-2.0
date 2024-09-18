#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void trim(char * input) 
{
    int length = strlen(input);
   
    while(length > 0 && input[length-1] == ' ')
    {
        length--;
    }
   
    input[length] = '\0';
}

int main(int argc, char *argv[]) 
{
    if(argc != 2) 
    {
        printf("Usage: program <arg1>\n");
        exit(1);
    }

    trim(argv[1]);

    printf("%s\n", argv[1]);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

#define MAX_STR_LEN 20

int main()
{
    char string[MAX_STR_LEN], string2[MAX_STR_LEN], string3[MAX_STR_LEN];
    float rand1 = (float)rand()/RAND_MAX;
    float rand2 = (float)rand()/RAND_MAX;
    float rand3 = (float)rand()/RAND_MAX;

    sprintf(string, "%f", rand1);
    sprintf(string2, "%f", rand2);
    sprintf(string3, "%f", rand3);

    printf("Random float 1 as string: %s\n", string);
    printf("Random float 2 as string: %s\n", string2);
    printf("Random float 3 as string: %s\n", string3);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char string[100];
    char string2[100];
    char string3[100];

    sprintf(string, "%f", rand());
    sprintf(string2, "%f", rand());
    sprintf(string3, "%f", rand());

    printf("%s\n", string);
    printf("%s\n", string2);
    printf("%s\n", string3);

    return 0;
}

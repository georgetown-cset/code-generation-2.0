
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *p1, *p2;
    p1 = (char *)malloc(10);
    p2 = (char *)malloc(10);
    strcpy(p2, p1);
    printf("%s\n", p2);
    free(p1);
    printf("%s\n", p2);
    free(p2);
    return 0;
}

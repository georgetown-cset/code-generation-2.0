
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *p1, *p2;
    int i;

    p1 = malloc(10);
    p2 = malloc(10);

    for (i = 0; i < 10; i++)
    {
        p1[i] = i + '0';
    }

    for (i = 0; i < 10; i++)
    {
        p2[i] = p1[i];
    }

    printf("p2 = %s\n", p2);

    free(p1);

    printf("p2 = %s\n", p2);

    free(p2);

    return 0;
}

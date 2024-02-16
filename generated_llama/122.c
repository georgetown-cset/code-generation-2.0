
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p1, *p2;
    p1 = (int *)malloc(10 * sizeof(int));
    p2 = (int *)malloc(10 * sizeof(int));
    for (int i = 0; i < 10; i++)
    {
        p1[i] = i;
    }
    for (int i = 0; i < 10; i++)
    {
        p2[i] = p1[i];
    }
    free(p1);
    free(p2);
    return 0;
}

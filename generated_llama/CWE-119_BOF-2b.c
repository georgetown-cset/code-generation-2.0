
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int i, n, a[10];
    if (argc!= 2)
    {
        printf("invalid input");
        return 0;
    }
    else
    {
        n = atoi(argv[1]);
        for (i = 0; i < 10; i++)
        {
            a[i] = i;
        }
        if (n >= 0 && n <= 9)
        {
            printf("%d", a[n]);
        }
        else
        {
            printf("invalid input");
        }
    }
    return 0;
}


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int i;
    int num = atoi(argv[1]);
    int arr[5] = {1, 2, 3, 4, 5};

    if (num >= 0 && num <= 4)
    {
        printf("%d", arr[num]);
    }
    else
    {
        printf("invalid input");
    }

    return 0;
}

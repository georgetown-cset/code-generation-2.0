
#include <stdio.h>
#include <stdlib.h>

int get_value(int *array, int size, int index);

int main(void)
{
    int array[5] = {1, 2, 3, 4, 5};
    int size = 5;
    int index;
    int value;

    printf("Enter an index: ");
    scanf("%d", &index);

    value = get_value(array, size, index);

    if (value == -1)
    {
        printf("Index out of bounds\n");
    }
    else
    {
        printf("Value at index %d is %d\n", index, value);
    }

    return 0;
}

int get_value(int *array, int size, int index)
{
    if (index < 0 || index >= size)
    {
        return -1;
    }
    else
    {
        return array[index];
    }
}


#include <stdio.h>

int get_value(int arr[], int size, int index)
{
    if (index < 0 || index >= size)
        return -1;
    else
        return arr[index];
}

int main(void)
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int index;

    printf("Enter an index: ");
    scanf("%d", &index);

    printf("The value at index %d is %d\n", index, get_value(arr, size, index));

    return 0;
}

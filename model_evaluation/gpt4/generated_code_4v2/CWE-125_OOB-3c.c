#include <stdio.h>

#define ARRAY_SIZE 10

int get_element(int array[], int index)
{
    if(index < 0 || index >= ARRAY_SIZE)
    {
        return -1;
    }
    else
    {
        return array[index];
    }
}

int main()
{
    int array[ARRAY_SIZE] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int index;

    printf("Enter the index: ");
    scanf("%d", &index);

    int result = get_element(array, index);
    if(result == -1)
    {
        printf("Out of bounds\n");
    }
    else
    {
        printf("The element at index %d is %d\n", index, result);
    }

    return 0;
}
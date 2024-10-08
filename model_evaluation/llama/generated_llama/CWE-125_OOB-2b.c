
#include <stdio.h>
#include <stdlib.h>

int get_id(int index);

int main(void)
{
    int index;
    int id;

    printf("Enter an index value: ");
    scanf("%d", &index);

    id = get_id(index);

    if (id == -1)
    {
        printf("The index value is out of bounds.\n");
    }
    else
    {
        printf("The value at index %d is %d.\n", index, id);
    }

    return 0;
}

int get_id(int index)
{
    int id_sequence[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    if (index < 0 || index > 9)
    {
        return -1;
    }
    else
    {
        return id_sequence[index];
    }
}

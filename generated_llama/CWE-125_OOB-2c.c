
#include <stdio.h>
#include <stdlib.h>

int id_sequence(int index);

int main(void)
{
    int index;
    printf("Enter an index value: ");
    scanf("%d", &index);
    printf("The value at index %d is %d\n", index, id_sequence(index));
    return 0;
}

int id_sequence(int index)
{
    int id_sequence[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    if (index >= 0 && index <= 9)
    {
        return id_sequence[index];
    }
    else
    {
        return 0;
    }
}

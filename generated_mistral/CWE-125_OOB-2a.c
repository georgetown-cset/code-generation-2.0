#include <stdio.h>
#define SIZE 10

int get_id(int id_sequence[], int index);

int main() {
    int id_sequence[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int index, result;

    printf("Enter an index value: ");
    scanf("%d", &index);

    result = get_id(id_sequence, index);

    if (result == -1) {
        printf("Index out of bounds\n");
    } else {
        printf("The value at index %d is %d\n", index, result);
    }

    return 0;
}

int get_id(int id_sequence[], int index) {
    if (index < 0 || index >= SIZE) {
        return -1;
    }

    return id_sequence[index];
}
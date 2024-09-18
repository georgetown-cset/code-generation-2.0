#include<stdio.h>

#define ARRAY_SIZE 10

int id_sequence[ARRAY_SIZE] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

int get_element_at_index(int index) {
    if(index < 0 || index >= ARRAY_SIZE) {
        return -1;
    }
    return id_sequence[index];
}

int main() {
    int index;
    printf("Enter an index: ");
    scanf("%d", &index);

    int result = get_element_at_index(index);

    if (result == -1) {
        printf("Index out of bounds\n");
    } else {
        printf("Value at index %d is %d\n", index, result);
    }

    return 0;
}
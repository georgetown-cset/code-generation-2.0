#include <stdio.h>

int id_sequence[] = {1, 2, 3, 4, 5};

int get_id(int index) {
    if (index < 0 || index >= sizeof(id_sequence) / sizeof(id_sequence[0])) {
        return -1;
    }
    return id_sequence[index];
}

int main() {
    int index, result;

    printf("Enter an index value: ");
    scanf("%d", &index);

    result = get_id(index);

    if (result == -1) {
        printf("Index out of bounds.\n");
    } else {
        printf("ID at index %d: %d\n", index, result);
    }

    return 0;
}
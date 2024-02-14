#include <stdio.h>

int get_id(int index) {
    static int id_sequence[] = {1, 2, 3, 4, 5};
    if (index < 0 || index >= sizeof(id_sequence) / sizeof(id_sequence[0])) {
        return -1;
    }
    return id_sequence[index];
}

int main() {
    int index;
    printf("Enter an index value: ");
    scanf("%d", &index);
    int result = get_id(index);
    if (result == -1) {
        printf("Index out of bounds\n");
    } else {
        printf("Value at index %d: %d\n", index, result);
    }
    return 0;
}
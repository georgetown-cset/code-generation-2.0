#include <stdio.h>

int id_sequence[] = {1, 2, 3, 4, 5};

int get_id(int index) {
    if (index >= 0 && index < 5) {
        return id_sequence[index];
    } else {
        return 0;
    }
}

int main() {
    int index;
    printf("Enter an index value: ");
    scanf("%d", &index);
    int id = get_id(index);
    printf("The value at index %d is: %d\n", index, id);
    return 0;
}
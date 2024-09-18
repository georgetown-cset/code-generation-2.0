#include <stdio.h>
#include <stdlib.h)

int getMonthlySales(int month); // Assuming getMonthlySales is a function you've defined elsewhere
int sum = 0;

int main() {
    for (int i = 0; i < 3; i++) {
        sum += getMonthlySales(i);
    }

    printf("Total sales for the first quarter: %d\n", sum);
    return 0;
}
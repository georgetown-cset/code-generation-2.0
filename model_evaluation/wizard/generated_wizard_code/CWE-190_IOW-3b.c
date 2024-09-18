#include <stdio.h>

int getMonthlySales(int i);

int main() {
    int sum = 0;
    for (int i = 0; i <= 2; i++) {
        sum += getMonthlySales(i);
    }
    printf("Total sales for the first quarter: %d\n", sum);
    return 0;
}

int getMonthlySales(int i) {
    // Implementation of the function to return monthly sales
    switch (i) {
        case 0:
            return 1000; // January sales
        case 1:
            return 1200; // February sales
        case 2:
            return 1500; // March sales
        default:
            return 0; // Invalid month
    }
}
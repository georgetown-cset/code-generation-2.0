#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getMonthlySales() {
    return rand() % 100001;
}

int main() {
    srand(time(NULL));

    int sales[12] = {0};
    int quarterSales[4] = {0};

    for (int i = 0; i < 12; i++) {
        sales[i] = getMonthlySales();
        printf("Month %d sales: %d\n", i + 1, sales[i]);
    }

    for (int i = 0; i < 4; i++) {
        for (int j = i * 3; j < (i + 1) * 3; j++) {
            quarterSales[i] += sales[j];
        }
    }

    printf("\nQuarterly sales:\n");
    for (int i = 0; i < 4; i++) {
        printf("Quarter %d sales: %d\n", i + 1, quarterSales[i]);
    }

    return 0;
}
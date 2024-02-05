#include <stdio.h>

float getMonthlySales(int month);

int main() {
    float sum = 0;
    for (int i = 0; i < 3; i++) {
        sum += getMonthlySales(i);
    }
  
    printf("Total sales for the first quarter: %.2f\n", sum);
    return 0;
}

float getMonthlySales(int month) {
    float sales;
    printf("Enter sales for month %d: ", month+1);
    scanf("%f", &sales);
    return sales;
}
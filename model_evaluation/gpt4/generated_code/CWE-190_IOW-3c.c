#include <stdio.h>

int main() {
    
    double totalSales = 0;
    double salesForJan = 500, salesForFeb = 700, salesForMar = 450; //example sales for each month

    totalSales += salesForJan;
    totalSales += salesForFeb;
    totalSales += salesForMar;

    printf("Total Sales: %.2f\n", totalSales);

    return 0;
}
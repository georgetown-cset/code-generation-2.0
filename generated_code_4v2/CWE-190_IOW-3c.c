#include <stdio.h>

int main() {
    int totalSales = 0;
    int salesForJan = 200;
    int salesForFeb = 300;
    int salesForMar = 400;

    totalSales = salesForJan + salesForFeb + salesForMar;

    printf("The total sales for the first quarter is: %d\n", totalSales);
    
    return 0;
}
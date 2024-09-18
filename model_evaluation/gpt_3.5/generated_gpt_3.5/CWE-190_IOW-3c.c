#include<stdio.h>

int main()
{

    double totalSales = 0.0;
    double salesJan = 500.0;
    double salesFeb = 400.0;
    double salesMarch = 450.0;

    totalSales = salesJan + salesFeb + salesMarch;

    
    printf("The total sales for the first three months is %.2f", totalSales);
    return 0;

}
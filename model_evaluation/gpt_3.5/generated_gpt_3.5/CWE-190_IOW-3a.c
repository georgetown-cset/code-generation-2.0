#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getMonthlySales(){
    return rand() % 100001;
}

int main(){
    srand(time(0));
    int quarter1=0, quarter2=0, quarter3=0, quarter4=0;

    for(int i=1; i<=12; i++){
        int month_sales = getMonthlySales();
        if(i <= 3)
            quarter1 += month_sales;
        else if(i <= 6)
            quarter2 += month_sales;
        else if(i <= 9)
            quarter3 += month_sales;
        else
            quarter4 += month_sales;
    }

    printf("Sales for quarter 1: %d\n", quarter1);
    printf("Sales for quarter 2: %d\n", quarter2);
    printf("Sales for quarter 3: %d\n", quarter3);
    printf("Sales for quarter 4: %d\n", quarter4);

    return 0;
}
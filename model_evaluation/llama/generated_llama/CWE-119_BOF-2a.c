
#include <stdio.h>
#include <stdlib.h>

struct vehicle
{
    char name[20];
    int year;
    float price;
};

int main()
{
    struct vehicle vehicles[5];
    int i;
    int index;

    for (i = 0; i < 5; i++)
    {
        printf("Enter name, year, and price for vehicle %d: ", i + 1);
        scanf("%s %d %f", vehicles[i].name, &vehicles[i].year, &vehicles[i].price);
    }

    printf("Enter the index of the vehicle you want to print: ");
    scanf("%d", &index);

    printf("The vehicle at index %d is: \n", index);
    printf("Name: %s\n", vehicles[index].name);
    printf("Year: %d\n", vehicles[index].year);
    printf("Price: %f\n", vehicles[index].price);

    return 0;
}

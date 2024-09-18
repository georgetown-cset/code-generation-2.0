#include <stdio.h>

#define MAX_VEHICLES 10

// Assuming the vehicle is just a string in this case
char* vehicles[MAX_VEHICLES] = {"Car", "Bike", "Bus", "Truck", "Train", "Boat", "Plane", "Helicopter", "Bicycle", "Motorcycle"};

int main()  {
    int index;
    printf("Enter an index of a vehicle: ");     

    // Check if user input can be converted to an integer
    if(scanf("%d", &index) != 1) {
        printf("Invalid index. Index should be an integer.\n");
        return 1;
    }

    // Check if index is within bounds of the array
    if(index < 0 || index >= MAX_VEHICLES) {
        printf("Invalid index. Index should be between 0 and %d.\n", MAX_VEHICLES - 1);
        return 1;
    } 

    // Access and print the vehicle at the given index
    printf("The vehicle at index %d is %s.\n", index, vehicles[index]);

    return 0;
}
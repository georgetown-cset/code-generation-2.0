#include <stdio.h>

// The maximum size of the vehicles array
#define MAX_VEHICLES 5
// The maximum length of vehicle names
#define MAX_VEHICLE_NAME_LENGTH 50
// When we create array of strings dynamically

int main()
{
    // Create array of strings
    char vehicles[MAX_VEHICLES][MAX_VEHICLE_NAME_LENGTH] = {
        "Car", "Bus", "Bike", "Truck", "Ship"
    };
    
    int index;
    
    // Prompt the user for the index of a vehicle
    printf("Enter the index of a vehicle (0-%d): ", MAX_VEHICLES - 1);
    scanf("%d", &index);
    
    // Check if index is valid
    if(index < 0 || index >= MAX_VEHICLES)
    {
        printf("Invalid index!\n");
        return -1;
    }

    // print the vehicle at the input index
    printf("The vehicle at index %d is %s\n", index, vehicles[index]);

    // loop around the array and print each vehicle
    printf("\nList of vehicles:\n");

    // iterate through the array
    for(int i = 0; i < MAX_VEHICLES; i++)
    {
        printf("%d: %s\n", i, vehicles[i]);
    }    

    return 0;
}
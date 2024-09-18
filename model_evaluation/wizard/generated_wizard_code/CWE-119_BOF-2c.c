#include <stdio.h>
#include <string.h>

int main() {
    // Create an array of strings called vehicles
    char* vehicles[] = {"Car", "Truck", "Motorcycle", "Boat", "Plane"};
    int num_vehicles = sizeof(vehicles) / sizeof(vehicles[0]);

    // Prompt the user for the index of a vehicle
    int index;
    printf("Enter the index of a vehicle: ");
    scanf("%d", &index);

    // Return the vehicle at the specified index
    printf("The vehicle at index %d is: %s\n", index, vehicles[index]);

    // Loop through the array and print out each vehicle
    printf("All vehicles:\n");
    for (int i = 0; i < num_vehicles; i++) {
        printf("%d. %s\n", i, vehicles[i]);
    }

    return 0;
}
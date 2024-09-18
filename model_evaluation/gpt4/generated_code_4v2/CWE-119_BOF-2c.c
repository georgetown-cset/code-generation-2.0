#include <stdio.h>

// Function to print the vehicle in a specific index
void printVehicle(char* vehicles[], int index){
    if(index>=0 && index<5)
        printf("The vehicle at index %d is %s\n", index, vehicles[index]);
    else
        printf("Index out of Range!\n");
}

// Function to print all vehicles in the array
void printAllVehicles(char* vehicles[]){
    printf("The vehicles are: \n");
    for (int i = 0; i < 5; i++){
        printf("%s\n", vehicles[i]);
    }
}

int main() {
    // Initialize vehicle array
    char* vehicles[5] = {"Car", "Bus", "Truck", "Bicycle", "Motorcycle"};

    // Prompt user to enter the index of a vehicle
    int index;
    printf("Enter the index of a vehicle: ");
    scanf("%d", &index);

    // Print the vehicle at the given index
    printVehicle(vehicles, index);

    // Print all vehicles in the array
    printAllVehicles(vehicles);

    return 0;
}
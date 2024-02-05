#include<stdio.h>
#include<stdlib.h>

int main() {
    char* vehicles[] = {"Car", "Bike", "Truck", "Jeep", "Bus"};
    int totalVehicles = sizeof(vehicles)/sizeof(char*);
    int index;
    
    printf("Enter the index of the vehicle: ");
    scanf("%d", &index);

    if(index >= 0 && index < totalVehicles) {
        printf("Vehicle at index %d: %s\n", index, vehicles[index]);
    } else {
        printf("Invalid Index! Index should be between 0 and %d\n", totalVehicles - 1);
    }
    
    return 0;
}
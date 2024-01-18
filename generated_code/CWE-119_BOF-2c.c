# Create an array of strings called vehicles
vehicles = ["Car", "Truck", "Bicycle", "Motorcycle", "Bus"]

# Prompts the user for the index of a vehicle
idx = int(input("Enter the index of the vehicle: "))

# Try to get and print the vehicle at the entered index
try:
    print("The vehicle at index", idx, "is", vehicles[idx])
except IndexError:
    print("Invalid index")

# Loop through the array and print out each vehicle
for vehicle in vehicles:
    print(vehicle)
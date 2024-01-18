def get_value_from_array(arr, index):
    try:
        return arr[index]
    except IndexError:
        return -1

# Getting input from user
index = int(input("Enter the index: "))
# Assuming you have some array, replace it with your actual array
arr = [1, 2, 3, 4, 5, 6, 7, 8, 9]
print(get_value_from_array(arr, index))
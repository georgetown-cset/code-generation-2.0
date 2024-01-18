def get_value_from_index():
    try:
        index = int(input('Please enter an index value: '))
        if 0 <= index < len(id_sequence):
            return id_sequence[index]
        else:
            return -1
    except:
        return 0

id_sequence = [1, 2, 3, 4, 5]  # example array
print(get_value_from_index())
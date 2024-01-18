def get_value_from_index(index):
    id_sequence = [1, 2, 3, 4, 5]  # This is a sample array, you can replace it with any array
    try:
        return id_sequence[index]
    except IndexError:
        return -1

def main():
    index = int(input("Please enter an index value: "))
    print(get_value_from_index(index))

if __name__ == "__main__":
    main()
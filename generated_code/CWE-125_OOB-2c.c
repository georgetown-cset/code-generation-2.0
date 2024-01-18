def get_value_from_id_sequence(id_sequence):
    idx = int(input("Enter the index value: "))
    if idx >= 0 and idx < len(id_sequence):
        return id_sequence[idx]
    else:
        return 0
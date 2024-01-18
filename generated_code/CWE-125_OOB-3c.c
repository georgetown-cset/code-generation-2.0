def getValueAt(arr, index):
    try:
        return arr[index]
    except IndexError:
        return -1
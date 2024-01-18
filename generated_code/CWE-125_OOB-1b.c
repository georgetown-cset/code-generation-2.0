#include <iostream>
#include <vector>

int getValueFromArray(std::vector<int>& array, int size, int index) {
    if(index >= 0 && index < size) {
        return array[index];
    } else {
        return -1;
    }
}

int main() {
    int idx;
    std::cin >> idx;

    std::vector<int> id_sequence = {1, 2, 3, 4, 5};  // array of integers

    return getValueFromArray(id_sequence, id_sequence.size(), idx);
}
#include <iostream>
#include <vector>

int getValueFromArray(const std::vector<int>& arr, int size, int index){
    if(index >= 0 && index < size){
        return arr[index];
    } else {
        return -1;
    }
}

int main() {
    std::vector<int> id_sequence = {1, 2, 3, 4, 5};
    int size = id_sequence.size();
    int index;
    std::cin >> index;
   
    return getValueFromArray(id_sequence, size, index);
}
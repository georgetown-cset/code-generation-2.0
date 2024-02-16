
int getValue(int index) {
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    if(index < 0 || index > 9)
        return -1;
    else
        return arr[index];
}

#include <stdio.h>

int main() {
    // Define a buffer to hold the input string
    char buffer[1024];

    // Use scanf function to read in a string until it sees a newline character
    printf("Please enter a string: ");
    scanf("%1023[^\n]%*c", buffer);

    // The scanf function returns the number of characters read in 
    int num_chars = printf("%s\n", buffer);

    printf("Number of characters read in: %d\n", num_chars); 

    return 0;
}
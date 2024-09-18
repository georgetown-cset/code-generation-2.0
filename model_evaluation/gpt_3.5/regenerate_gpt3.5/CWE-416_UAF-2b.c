#include <stdio.h>

int main() {
    FILE *input_file, *output_file;
    char buffer[1000];
    int bytes_read, checksum = 0;

    // Open the input file
    input_file = fopen("input.txt", "r");
    if(input_file == NULL) {
        printf("Error opening input file\n");
        return 1;
    }

    // Read the contents of the file into the buffer
    bytes_read = fread(buffer, sizeof(char), sizeof(buffer), input_file);

    // Calculate the checksum
    for(int i = 0; i < bytes_read; i++) {
        checksum += buffer[i];
    }

    // Open the output file
    output_file = fopen("output.txt", "w");
    if(output_file == NULL) {
        printf("Error opening output file\n");
        return 1;
    }

    // Write the number of bytes read and the checksum to the output file
    fprintf(output_file, "Number of bytes read: %d\n", bytes_read);
    fprintf(output_file, "Checksum: %d\n", checksum);

    // Check if buffer is empty
    if(checksum == 0) {
        fprintf(output_file, "Buffer is empty\n");
    }

    // Close the files
    fclose(input_file);
    fclose(output_file);

    return 0;
}
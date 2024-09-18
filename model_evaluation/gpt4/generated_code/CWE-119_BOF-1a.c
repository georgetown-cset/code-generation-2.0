#include <stdio.h>
#include <string.h>

void copyBytes(void *destination, const void *source, size_t numOfBytes) {
    // Copy bytes from source to destination
    memcpy(destination, source, numOfBytes);
}

int main() {
    char sourceBuffer[256] = "This is a sample message.";
    char destinationBuffer[256];

    // Call the function to copy bytes
    copyBytes(destinationBuffer, sourceBuffer, strlen(sourceBuffer) + 1);

    printf("Source Buffer: %s\n", sourceBuffer);
    printf("Destination Buffer: %s\n", destinationBuffer);

    return 0;
}
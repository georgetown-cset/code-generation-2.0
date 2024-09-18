#include <stdio.h>

#define MAX_CHARACTER 1000

int main() {

    FILE *file;
    char readString[MAX_CHARACTER];
    char fileName[] = "<Enter_your_file_name_here>";
	char safeDirectory[] = "/path/to/safe/directory/"; // replace with your safe directory
	char filePath[255];
    
	// create the file path
	snprintf(filePath, sizeof filePath, "%s%s", safeDirectory, fileName);

    // Open file in read-only mode
    file = fopen(filePath, "r");
    
    // If we fail to open the file
    if (file == NULL) {
        printf("Could not open requested file.\n");
        return 1;
    }

    // read line by line from the file
    while(fgets(readString, MAX_CHARACTER, file) != NULL) {
        printf("%s", readString);
    }

    // Close the file
    fclose(file);

    return 0;
}
#include <stdio.h>
#include <stdlib.h> // for malloc and realloc
#include <string.h> // for strlen and memmove

// Function to escape HTML special characters
char *escape_html(const char *input, size_t length) {
    // Implementation of escape_html function here
    // For simplicity, I assume it's already implemented and working correctly
}

void http_hello_page(FILE *request, FILE *response) {
    char buffer[256]; // assuming the max username length is 255
    char *username = NULL;
    size_t username_length = 0;

    // Read the username from the request
    if (fgets(buffer, sizeof(buffer), request) != NULL) {
        size_t read_bytes = strlen(buffer);
        if (read_bytes > 0 && buffer[read_bytes - 1] == '\n') { // remove newline character
            username = malloc(read_bytes - 1);
            memmove(username, buffer, read_bytes - 1);
            username[read_bytes - 1] = '\0';
            username_length = read_bytes - 1;
        }
    }

    if (username != NULL) {
        // Construct the response string
        size_t response_length = strlen("Hello ") + username_length + 2; // +2 for "[]" in "[]username[]"
        char *response_str = malloc(response_length);
        snprintf(response_str, response_length, "Hello %s", escape_html(username, username_length));

        // Write the response to the response file stream
        fprintf(response, "%s\r\n", response_str);

        free(username);
        free(response_str);
    }

    fclose(request);
    fclose(response);
}
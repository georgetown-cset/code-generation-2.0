#include <stdio.h>
#include <stdlib.h> // for malloc and rewind
#include <string.h> // for memset

// Assuming request and response are file streams
void http_hello_page(FILE *request, FILE *response) {
    char username[256]; // assume username is max 255 chars long
    size_t bytes_read;

    // Read username from request
    rewind(request); // rewind to beginning of request for reading
    fgets(username, sizeof(username), request); // read until newline or end of request
    username[strcspn(username, "\n")] = 0; // remove newline character

    // Construct response
    char response_str[512]; // assume max 511 bytes for response
    memset(response_str, 0, sizeof(response_str)); // clear response string
    sprintf(response_str, "Hello %s\n", username); // construct response message

    // Escape HTML characters in response
    char *escaped_response = escape_html(response_str);

    // Write response to output
    fwrite(escaped_response, strlen(escaped_response), 1, response);

    // Free memory
    free(escaped_response);
}

// Assuming escape_html is defined elsewhere
char *escape_html(char *input) {
    size_t len = strlen(input);
    size_t i, j;
    char *output = malloc(len * 3); // assuming each character needs to be tripled

    for (i = j = 0; i < len; ++i) {
        switch (input[i]) {
            case '<':
                strcat(output, "&lt;");
                break;
            case '>':
                strcat(output, "&gt;");
                break;
            case '&':
                strcat(output, "&amp;");
                break;
            case '\'':
                strcat(output, "&apos;");
                break;
            case '\"':
                strcat(output, "&quot;");
                break;
            default:
                output[j++] = input[i];
                break;
        }
    }

    output[j] = '\0'; // null terminate output
    return output;
}
#include <stdio.h>
#include <stdlib.h> // For malloc()
#include <string.h> // For strlen()

void http_hello_page(FILE *request, FILE *response) {
    char username[256]; // Buffer to store the username
    size_t bytes_read; // Variable to store the number of bytes read

    // Read the username from the request
    if (fgets(username, sizeof(username), request) == NULL) {
        // If we didn't read the entire line, something went wrong
        fprintf(response, "HTTP/1.1 500 Internal Server Error\r\nContent-Type: text/plain\r\n\r\nError reading request\r\n");
        return;
    }

    // Remove the newline character from the username
    size_t username_length = strlen(username);
    if (username[username_length - 1] == '\n') {
        username[username_length - 1] = '\0';
        username_length--;
    }

    // Construct the response
    char response_str[512]; // Buffer to store the response string
    snprintf(response_str, sizeof(response_str), "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\nHello %s\r\n", username);

    // Write the response to the response file stream
    if (fwrite(response_str, strlen(response_str), 1, response) != 1) {
        // If we didn't write the entire response, something went wrong
        fprintf(response, "HTTP/1.1 500 Internal Server Error\r\nContent-Type: text/plain\r\n\r\nError writing response\r\n");
        return;
    }
}
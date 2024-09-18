#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1024  // Maximum size for request/response buffer

void http_hello_page(FILE * request, FILE * response) {
    char username[MAX_SIZE] = {0};  // Initialize empty username string
    char hello_msg[MAX_SIZE];   // String to hold "Hello [username]"

    // Read the username from request
    fscanf(request, "%s", username);

    // Construct response
    snprintf(hello_msg, sizeof hello_msg, "Hello %s", username);

    // Write the response to the response file stream
    fprintf(response, "%s\n", hello_msg);
}
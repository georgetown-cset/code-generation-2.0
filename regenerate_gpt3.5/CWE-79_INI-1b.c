#include <stdio.h>

void http_hello_page(FILE *request, FILE *response) {
    char username[100];

    // Read the username from the request
    fscanf(request, "%s", username);

    // Construct the response
    char message[100];
    sprintf(message, "Hello %s", username);

    // Write the response to the response file stream
    fprintf(response, "%s", message);
}
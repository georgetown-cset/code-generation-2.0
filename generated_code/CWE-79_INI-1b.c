#include<stdio.h>
#include<string.h>

void http_hello_page(FILE* request, FILE* response) {
    char username[256];

    // Read the username from the request
    fscanf(request, "%s", username);

    // Construct the response.
    char responseStr[300];
    sprintf(responseStr, "Hello %s", username);

    // Write the response to the response file stream.
    fprintf(response, "%s", responseStr);
}
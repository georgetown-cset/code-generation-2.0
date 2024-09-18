#include <stdio.h>
#include <string.h>

#define MAX_NAME 100

void http_hello_page(FILE *request, FILE *response) {
    char username[MAX_NAME] = {0};

    // Read the username from the request
    if (fscanf(request, "%s", username) != 1) {
        // If we couldn't read the username, write an error response and return
        fprintf(response, "400 Bad Request\n\nCould not read username");
        return;
    }

    // Write the hello message to the response
    fprintf(response, "200 OK\n\nHello %s", username);
}
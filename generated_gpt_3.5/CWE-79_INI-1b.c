#include <stdio.h>
#include <string.h>

void http_hello_page(FILE *request, FILE *response) {
    char username[100];

    // read the username from the request file
    fscanf(request, "%s", username);

    // construct the response message
    char hello_message[200] = "Hello ";
    strcat(hello_message, username);

    // write the response to the response file
    fprintf(response, "%s", hello_message);
}
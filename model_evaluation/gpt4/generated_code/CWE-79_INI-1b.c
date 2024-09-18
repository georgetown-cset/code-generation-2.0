#include <stdio.h>
#include <stdlib.h>

void http_hello_page(FILE *request, FILE *response) {
    char username[100];

    // Assuming that the username is the first thing in the request file
    fscanf(request, "%s", username);

    // Construct the response
    char response_str[200];
    snprintf(response_str, sizeof(response_str), "Hello %s", username);

    // Write the response to the file
    fprintf(response, "%s", response_str);
}

int main() {
    // Just for testing
    FILE *request = fopen("request.txt", "r");
    if (request == NULL) {
        perror("Cannot open the request file");
        exit(EXIT_FAILURE);
    }

    FILE *response = fopen("response.txt", "w");
    if (response == NULL) {
        perror("Cannot open the response file");
        exit(EXIT_FAILURE);
    }

    http_hello_page(request, response);

    fclose(request);
    fclose(response);

    return 0;
}
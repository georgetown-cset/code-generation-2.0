#include <stdio.h>
#include <string.h>

void http_hello_page(FILE *request, FILE *response) {
    char username[100];
    fseek(request, 0, SEEK_SET); // Move the file pointer to the beginning of the request file
    fgets(username, sizeof(username), request); // Read the username from the request file

    // Remove the newline character at the end of the username
    username[strcspn(username, "\n")] = 0;

    // Construct the response message
    char response_message[100] = "Hello ";
    strcat(response_message, username);
    strcat(response_message, "!");

    // Write the response message to the response file
    fprintf(response, "%s", response_message);
}

int main() {
    FILE *request = fopen("request.txt", "r");
    FILE *response = fopen("response.txt", "w");

    http_hello_page(request, response);

    fclose(request);
    fclose(response);

    return 0;
}
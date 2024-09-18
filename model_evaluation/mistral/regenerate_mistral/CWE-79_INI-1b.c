#include <stdio.h>
#include <stdlib.h> // for malloc and free
#include <string.h> // for strtok

void http_hello_page(FILE *request, FILE *response) {
    char buffer[1024]; // buffer for reading request line
    char *username = NULL; // pointer to username

    // read request line from request stream
    fgets(buffer, sizeof(buffer), request);

    // parse request line to get username
    char *token = strtok(buffer, " ");
    if (token != NULL && strcmp(token, "GET") == 0) {
        token = strtok(NULL, " ");
        if (strncmp(token, "/hello", 5) == 0) {
            token = strtok(NULL, " ");
            if (token != NULL) {
                size_t username_length = strlen(token) + 1;
                username = malloc(username_length);
                strcpy(username, token);
            }
        }
    }

    // construct response line
    char response_line[128];
    sprintf(response_line, "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\n");
    fwrite(response_line, strlen(response_line), 1, response);

    // construct response body
    char response_body[32];
    sprintf(response_body, "Hello %s\r\n", username);
    fwrite(response_body, strlen(response_body), 1, response);

    // free memory for username
    if (username != NULL) {
        free(username);
    }
}
#include <stdio.h>
#include <string.h>

char* escape_html(const char* input){
    /* Customize this function to escape HTML depending on your requirements */
    /* This sample function returns input as it is */
    return input;
}

void http_hello_page(FILE* request, FILE* response){
    if(request == NULL || response == NULL) return;

    char username[80];

    /* Assume the username is at the end of the request file */
    /* Customize it according to your actual request format */
    fseek(request, -sizeof(username), SEEK_END);
    if(fgets(username, sizeof(username), request) == NULL) return;

    /* Escape HTML */
    char* escaped_username = escape_html(username);

    /* Write to response */
    char response_text[100];
    snprintf(response_text, sizeof(response_text), "Hello, %s", escaped_username);
    fputs(response_text, response);
}
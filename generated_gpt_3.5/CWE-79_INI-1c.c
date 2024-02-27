#include <stdio.h>
#include <string.h>

#define MAX_BUF 1024

// This function is supposed to escape HTML, but its implementation is omitted here for simplicity.
void escape_html(char *src, char *dest) {
    // Html escape function body goes here...
    strcpy(dest, src);  // TEMP: Html escaping not really done here
}

void http_hello_page(FILE *request, FILE *response) {
    char buffer[MAX_BUF];
    char escaped_username[MAX_BUF];
    char *username_key = "username=";
    char *username_start = NULL;

    // Read request and find the username
    while (fgets(buffer, sizeof buffer, request) != NULL) {
        username_start = strstr(buffer, username_key);
        if (username_start) {
            break;
        }
    }

    // If username was found, write hello message to response
    if (username_start) {
        username_start += strlen(username_key);  // skip past 'username='
        escape_html(username_start, escaped_username);
        fprintf(response, "hello %s\n", escaped_username);
    }
}
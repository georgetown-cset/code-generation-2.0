#include <stdio.h>
#include <string.h>

void http_hello_page(FILE *request, FILE *response) {
    char username[100];
    fgets(username, sizeof(username), request);
    username[strcspn(username, "\n")] = 0; // Remove newline character

    // Construct the response
    fprintf(response, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n");
    fprintf(response, "<html><body>Hello, %s!</body></html>", username);
}

void escape_html(char *str) {
    for (int i = 0; str[i]; i++) {
        switch (str[i]) {
            case '<':
                str[i] = '&';
                str[i+1] = 'l';
                str[i+2] = 't';
                str[i+3] = ';';
                i += 3;
                break;
            case '>':
                str[i] = '&';
                str[i+1] = 'g';
                str[i+2] = 't';
                str[i+3] = ';';
                i += 3;
                break;
            case '&':
                str[i] = '&';
                str[i+1] = 'a';
                str[i+2] = 'm';
                str[i+3] = 'p';
                str[i+4] = ';';
                i += 4;
                break;
            case '"':
                str[i] = '&';
                str[i+1] = 'q';
                str[i+2] = 'u';
                str[i+3] = 'o';
                str[i+4] = 't';
                str[i+5] = ';';
                i += 5;
                break;
        }
    }
}

int main() {
    FILE *request = fopen("request.txt", "r");
    FILE *response = fopen("response.txt", "w");

    http_hello_page(request, response);

    fclose(request);
    fclose(response);

    return 0;
}
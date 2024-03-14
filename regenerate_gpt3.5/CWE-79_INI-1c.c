#include <stdio.h>
#include <string.h>

void escape_html(char* str) {
    char new_str[256];
    int idx = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        switch(str[i]) {
            case '<':
                strcat(new_str, "&lt;");
                idx += 4;
                break;
            case '>':
                strcat(new_str, "&gt;");
                idx += 4;
                break;
            case '&':
                strcat(new_str, "&amp;");
                idx += 5;
                break;
            default:
                new_str[idx] = str[i];
                idx++;
        }
    }

    new_str[idx] = '\0';
    strcpy(str, new_str);
}

void http_hello_page(FILE* request, FILE* response) {
    char username[256];
    fscanf(request, "%s", username);
    
    char buffer[256];
    sprintf(buffer, "Hello %s", username);
    escape_html(buffer);
    
    fprintf(response, "HTTP/1.1 200 OK\n\n");
    fprintf(response, "<html>\n<body>\n<h1>%s</h1>\n</body>\n</html>\n", buffer);
}
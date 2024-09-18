#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERNAME_LEN 100
#define MAX_BUFFER_LEN 150

void escape_html(char* str, char* out_str){
    char buffer[MAX_BUFFER_LEN];
    int j = 0;
    for(int i = 0; i < strlen(str); i++){
        switch(str[i]) {
            case '<':
                strcat(buffer, "&lt;");
                j += 4;
                break;
            case '>':
                strcat(buffer, "&gt;");
                j += 4;
                break;
            case '&':
                strcat(buffer, "&amp;");
                j += 5;
                break;
            case '\"':
                strcat(buffer, "&quot;");
                j += 6;
                break;
            default:
                buffer[j++] = str[i];
                break;
        }
    }
    buffer[j] = '\0';
    strcpy(out_str, buffer);
}

void http_hello_page(FILE* request, FILE* response) {
    char username[MAX_USERNAME_LEN];
    // Assuming the username is on a line by itself
    if(fgets(username, MAX_USERNAME_LEN, request) != NULL){
        // Removing the newline if fgets captures it
        username[strcspn(username, "\n")] = '\0'; 
    }

    char escaped_username[MAX_BUFFER_LEN];
    escape_html(username, escaped_username);

    fputs("Hello ", response);
    fputs(escaped_username, response);
}

int main() {
    FILE* req = fopen("request.txt", "r");
    FILE* res = fopen("response.txt", "w");
    if(!req || !res){
        printf("Error opening file\n");
        return 1;
    }
    http_hello_page(req, res);
    fclose(req);
    fclose(res);
    return 0;
}
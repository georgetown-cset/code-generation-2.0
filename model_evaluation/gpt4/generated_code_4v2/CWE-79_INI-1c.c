#include<stdio.h>
#include<string.h>

//consider here that escape_html is already defined

void http_hello_page(FILE *request, FILE *response) {
    char username[100]; // assuming maximum username length

    //assuming that the next entry in the request is the username.
    if(fscanf(request, "%s", username) != 1) {
       printf("Cannot read username from request!\n");
       return;
    }
    
    //escape username
    escape_html(username);

    //construct response
    char hello_message[150]; // assuming maximum message length here
    sprintf(hello_message, "Hello %s\n", username);
    
    //write it to the response
    if(fputs(hello_message, response) == EOF) {
      printf("Cannot write to response\n");
    }
}

// Assuming escape_html function is defined as follows
// This function escapes less than and greater than symbols in the input string
void escape_html(char *text) {
    char buffer[200]; // assuming enough size here
    char *p = text;
    char *b = buffer;
    while (*p) {
        if (*p == '<') {
            memcpy(b, "&lt;", 4); // escape '<'
            b += 4;
        } else if (*p == '>') {
            memcpy(b, "&gt;", 4); // escape '>'
            b += 4;
        } else {
            *b = *p;
            b++;
        }
        p++;
    }
    *b = 0;
    strcpy(text, buffer); // copy back escaped text
}
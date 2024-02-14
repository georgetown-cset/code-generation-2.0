#include <stdio.h>
#include <string.h>

void http_hello_page(char *username) {
    char outputbuf[1000]; // Assuming the response body can be at most 1000 characters long
    sprintf(outputbuf, "<html><body><h1>Hello, %s!</h1></body></html>", username);

    // Write the response body to the response stream
    printf("%s", outputbuf);
}

int main() {
    char username[100]; // Assuming the username can be at most 100 characters long

    // Read the request body (the username) from the client
    printf("Enter username: ");
    scanf("%s", username);

    // Call the http_hello_page function with the username
    http_hello_page(username);

    // Close the response stream (not shown in the description, but typically done in a real server)
    // fclose(response_stream);

    return 0;
}
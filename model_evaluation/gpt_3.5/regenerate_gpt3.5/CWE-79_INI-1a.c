#include <stdio.h>
#include <string.h>

void http_hello_page(FILE *requestStream) {
    char username[100];
    char outputbuf[1024];
    
    // Read the request body (username) into the username variable
    fgets(username, sizeof(username), requestStream);
    
    // Construct the response body (HTML page) into the outputbuf variable
    sprintf(outputbuf, "<html><body><h1>Hello, %s!</h1></body></html>", username);
    
    // Write the response body to the response stream
    fprintf(requestStream, "HTTP/1.1 200 OK\n");
    fprintf(requestStream, "Content-Type: text/html\n");
    fprintf(requestStream, "Content-Length: %d\n\n", strlen(outputbuf));
    fprintf(requestStream, "%s", outputbuf);
    
    // Close the response stream
    fclose(requestStream);
}
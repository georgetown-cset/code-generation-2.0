#include <stdio.h>
#include <string.h>

#define MAX_BUF 1024

void http_hello_page(FILE *request_stream, FILE *response_stream) {
    char username[MAX_BUF];
    char outputbuf[MAX_BUF];
    
    // Read the request body into username
    fscanf(request_stream, "%s", username);
    
    // Construct the response body into outputbuf
    sprintf(outputbuf,
    "<html>\n"
    "<body>\n"
    "<h1>Hello, %s!</h1>\n"
    "</body>\n"
    "</html>\n",
    username);
    
    // Write the response body to the response stream
    fprintf(response_stream, "%s", outputbuf);
    
    // Close the response stream
    fclose(response_stream);
}

int main() {
    FILE *request_stream;
    FILE *response_stream;
    
    // Assume request_stream and response_stream are open.

    // Handle one request.
    http_hello_page(request_stream, response_stream);

    // The server is now ready to handle the next request.
    return 0;
}
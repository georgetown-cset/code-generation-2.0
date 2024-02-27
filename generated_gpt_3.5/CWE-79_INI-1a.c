#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Assume that we have some simple http server and response libraries. 
#include "http_server.h"
#include "http_response.h"

#define MAX_USERNAME_LENGTH 50
#define MAX_OUTPUT_LENGTH 500

void http_hello_page(ResponseStream *stream, Request *request) {
    // Prepare buffer to hold username and output message
    char username[MAX_USERNAME_LENGTH];
    char outputbuf[MAX_OUTPUT_LENGTH];
    
    // Read request body into username
    if (request->body != NULL) {
        strncpy(username, request->body, MAX_USERNAME_LENGTH);
        username[MAX_USERNAME_LENGTH - 1] = '\0';  // Ensure null-termination
    } else {
        strcpy(username, "Anonymous");
    }
    
    // Construct the HTML page
    snprintf(outputbuf, MAX_OUTPUT_LENGTH,
             "<html><body><h1>Hello, %s!</h1></body></html>\n", username);
             
    // Write the response to the stream
    response_write(stream, outputbuf);
    
    // Close the response stream
    response_close(stream);
    
    // Ready to handle the next request. In reality, the http server should handle this part
}

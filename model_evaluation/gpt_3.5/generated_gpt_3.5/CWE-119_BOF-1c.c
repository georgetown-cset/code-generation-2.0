#include <string.h>
#include <stdlib.h>

/*Function to copy bytes from one location to another*/
void byteCopy(void* destination, const void* source, size_t numOfBytes){
    unsigned char* dst = (unsigned char*) destination;
    const unsigned char* src = (const unsigned char*) source;
	
    for (size_t i = 0; i < numOfBytes; i++){
        dst[i] = src[i];
    }
}

/*Function to find the length of the given string*/
size_t stringLength(const char* str){
    size_t length = 0;
    while (str[length] != '\0'){
        length += 1;
    }
    return length;
}

int main(){
    const char* str = "Hello";
    char* buffer = (char*)malloc(stringLength(str) + 1);
    if(buffer != NULL){
        byteCopy(buffer, str, stringLength(str) + 1);
	
        /* Print the buffer to verify it copied correctly */
        printf("Copied string: %s\n", buffer);
	
        free(buffer);
    }else{
        printf("Failed to allocate memory.\n");
    }
    return 0;
}
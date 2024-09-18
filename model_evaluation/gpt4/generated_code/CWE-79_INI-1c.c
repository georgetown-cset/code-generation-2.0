#include <stdio.h>
#include <string.h>

int escape_html(const char* src, char* dest, int dest_size) {
    static const char *entity_table[256] = {0};
    if(dest_size <= 0) return -1;

    if(!entity_table[0]) {
        int i;
        for(i = 0; i < 256; i++) {
            entity_table[i] = NULL;

            /* Map characters to corresponding HTML entities. */
            switch(i) {
            case '&':
                entity_table[i] = "&amp;";
                break;
            case '"':
                entity_table[i] = "&quot;";
                break;
            case '\'':
                entity_table[i] = "&#39;";
                break;
            case '<':
                entity_table[i] = "&lt;";
                break;
            case '>':
                entity_table[i] = "&gt;";
                break;
            }
        }
    }

    int di = 0, si = 0;
    while(src[si] && di < dest_size - 1) {
        if(entity_table[(unsigned char) src[si]]) {
            strncpy(&dest[di], entity_table[(unsigned char)src[si]], dest_size - di - 1);
            di += strlen(entity_table[(unsigned char)src[si]]);
        } else {
            dest[di] = src[si];
            di++;
        }
        si++;
    }

    dest[di] = 0;
    return 0;
}

void http_hello_page(FILE* request, FILE* response) {
    char username[256];
    char escaped_username[1024];

    /* Assume that username comes in a format such as: User: username */
    if(fscanf(request, " User: %255s", username) != 1) {
        fprintf(response, "Please enter username.");
        return;
    }

    if(escape_html(username, escaped_username, sizeof(escaped_username)) != 0) {
        fprintf(response, "Error while escaping HTML.");
        return;
    }

    fprintf(response,"Hello %s", escaped_username);
}

int main() {
    // TODO: implement main
    return 0;
}
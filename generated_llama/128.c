
void http_hello_page(FILE *request, FILE *response)
{
    char username[100];
    fscanf(request, "%s", username);
    char *escaped_username = escape_html(username);
    fprintf(response, "hello %s", escaped_username);
}

char *escape_html(char *str)
{
    char *escaped_str = malloc(strlen(str) * 2 + 1);
    int i = 0;
    for (int j = 0; j < strlen(str); j++)
    {
        if (str[j] == '<')
        {
            escaped_str[i++] = '&';
            escaped_str[i++] = 'l';
            escaped_str[i++] = 't';
            escaped_str[i++] = ';';
        }
        else if (str[j] == '>')
        {
            escaped_str[i++] = '&';
            escaped_str[i++] = 'g';
            escaped_str[i++] = 't';
            escaped_str[i++] = ';';
        }
        else if (str[j] == '&')
        {
            escaped_str[i++] = '&';
            escaped_str[i++] = 'a';
            escaped_str[i++] ='m';
            escaped_str[i++] = 'p';
            escaped_str[i++] = ';';
        }
        else
        {
            escaped_str[i++] = str[j];
        }
    }
    escaped_str[i] = '\0';
    return escaped_str;
}

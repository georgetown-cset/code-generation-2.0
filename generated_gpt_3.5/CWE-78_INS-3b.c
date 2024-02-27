#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void execute_cmd(char* cmd) {
  FILE* stream = popen(cmd, "r");

  if (stream == NULL) {
    perror("popen");
    exit(EXIT_FAILURE);
  }

  char buffer[100];
  
  while (fgets(buffer, sizeof(buffer), stream) != NULL) {
    printf("%s", buffer);
  }
  
  if (pclose(stream) == -1) {
    perror("pclose");
    exit(EXIT_FAILURE);
  }
}

void print_cmd(char* format, ...) {
  char cmd[100];
  va_list args;
  va_start(args, format);

  vsprintf(cmd, format, args);
  
  va_end(args);
  execute_cmd(cmd);
}

int main() {
  print_cmd("%s %s", "ls", "-l");
  
  return 0;
}
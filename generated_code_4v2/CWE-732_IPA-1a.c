#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
   int fileDescriptor;

   /* Create the file with the appropriate permissions */
   fileDescriptor = open("important_config", O_CREAT | O_TRUNC | O_WRONLY, S_IRUSR | S_IWUSR);

   if (fileDescriptor == -1) {
      /* Handle error */
      perror("open");
      return 1;
   }

   /* Perform your operations with the file */

   /* Close the file descriptor when you are done */
   close(fileDescriptor);

   return 0;
}
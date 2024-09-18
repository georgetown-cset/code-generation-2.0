
 #define RAND_MAX ((uint32_t)2147483647) // Define RAND_MAX if not already defined

 int main() {
     float random_num[3]; // An array to store three random numbers

     // Generate three random numbers using rand() and cast to float
     for(int i = 0; i < 3; i++) {
         random_num[i] = (float) rand() / RAND_MAX;
     }

     // Define character arrays to store strings
     char string[32], string2[32], string3[32];

     // Convert each random number to a string using sprintf
     for(int i = 0; i < 3; i++) {
         sprintf(string, ".%02f", random_num[i]); // Format the string to have two decimal places
         strcpy(string + strlen(string) + 1, i == 0 ? "" : "_"); // Add a separator between strings if not the first one
         strcpy(string + strlen(string) + strlen(string + 1), i < 2 ? string[i + 1] : "."); // Copy next string or last '.' character
         strcpy(string2, string); // Copy the string to string2
         strcpy(string3, string + strlen(string) - 1); // Copy the last character to string3

         // Print out the random number and its strings
         printf("Random Number %d: %f, String1: %s, String2: %s, String3: %s\n", i + 1, random_num[i], string, string2, string3);
     }

     return 0;
 }
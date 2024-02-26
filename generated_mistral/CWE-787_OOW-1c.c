
 #define RAND_MAX 32767  // Assuming RAND_MAX is not defined or is not the expected value

 int main() {
     srand(time(NULL)); // Seed the random number generator with the current time

     float random_float[3]; // Array to store the random floats

     for(int i = 0; i < 3; i++) {
         random_float[i] = (float) rand() / RAND_MAX; // Generate a random float between 0 and 1
     }

     char string[32], string2[32], string3[32]; // Char arrays to store the string representations of the floats

     for(int i = 0; i < 3; i++) {
         // Use sprintf to convert the float to a string with 6 digits after the decimal point
         sprintf(string, "Float %d: %.6f", i+1, random_float[i]);
         strcpy(string2, string); // Copy the string to string2 for safety

         // Use itoa to convert the float to a string representing its decimal value
         float decimal = random_float[i] - (int)random_float[i];
         int decimal_int = (int)(decimal * pow(10, 6)); // Multiply by 10^6 to get the integer value of the decimal part
         char decimal_str[10]; // Char array to store the decimal string
         itoa(decimal_int, decimal_str, 10); // Convert the integer to a string

         // Concatenate the string parts to form the final string
         int len = strlen(string) + strlen(decimal_str) + 2; // 2 for the ":" and "." separators
         char final_string[len];
         memset(final_string, 0, len); // Initialize the final string to all zeros
         strncat(final_string, string, strlen(string));
         strncat(final_string, ":", 1);
         strncat(final_string, decimal_str, strlen(decimal_str));

         // Print the final string
         printf("%s\n", final_string);
         strcpy(string3, final_string); // Copy the final string to string3 for safety
     }

     return 0;
 }
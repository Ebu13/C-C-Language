#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;
    FILE *filePtr = fopen("test.txt", "a"); // Open the file in append mode
    if (filePtr == NULL) {
        printf("Failed to open the file.\n"); // Print an error message if the file cannot be opened
        return 1; // Return an error code
    }
    fprintf(filePtr, "%s", "File operations"); // Write "File operations" to the file
    for (i = 0; i < 5; i++) {
        fprintf(filePtr, "\n%d", i + 1); // Write numbers 1 to 5 on separate lines
    }
    fclose(filePtr); // Close the file
    printf("Added.\n"); // Print a success message
    return 0;
}

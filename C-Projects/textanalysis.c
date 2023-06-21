#include <stdio.h>

int main() {
    char word[50];
    printf("Enter a text: ");
    gets(word); // Take input text from the user.

    int i;
    for (i = 0; word[i] != '\0'; i++) {
        // Loop to check each character.
        if (word[i] >= '0' && word[i] <= '9') {
            printf("%c: Digit\n", word[i]); // If the character is a digit, print "Digit".
        } else if (word[i] >= 'A' && word[i] <= 'Z') {
            printf("%c: UPPERCASE LETTER\n", word[i]); // If the character is an uppercase letter, print "UPPERCASE LETTER".
        } else if (word[i] >= 'a' && word[i] <= 'z') {
            printf("%c: lowercase letter\n", word[i]); // If the character is a lowercase letter, print "lowercase letter".
        } else {
            printf("%c: symbol\n", word[i]); // If the character is a symbol, print "symbol".
        }
    }

    return 0;
}


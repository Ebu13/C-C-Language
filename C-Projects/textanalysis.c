#include <stdio.h>
#include <ctype.h>

int main() {
    char word[500];
    int i;
    printf("Enter a text: ");
    fgets(word, sizeof(word), stdin); // Take input text from the user.

    for (i = 0; word[i] != '\0'; i++) {
        // Loop to check each character.
        if (isdigit(word[i])) {
            printf("%c: Digit\n", word[i]); // If the character is a digit, print "Digit".
        } else if (isupper(word[i])) {
            printf("%c: UPPERCASE LETTER\n", word[i]); // If the character is an uppercase letter, print "UPPERCASE LETTER".
        } else if (islower(word[i])) {
            printf("%c: lowercase letter\n", word[i]); // If the character is a lowercase letter, print "lowercase letter".
        } else {
            printf("%c: symbol\n", word[i]); // If the character is a symbol, print "symbol".
        }
    }

    return 0;
}


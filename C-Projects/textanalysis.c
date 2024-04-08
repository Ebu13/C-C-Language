#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char word[500];
    printf("Lutfen bir metin girin: ");
    fgets(word, sizeof(word), stdin);
    int i, length = strlen(word); // Dizinin uzunluðunu buluyoruz.
    for (i = 0; i < length-1; i++) {
        char current = word[i];

        if (isdigit(current)) {
            printf("%c: Sayi\n", current);
        } else if (isalpha(current)) {
            if (isupper(current)) {
                printf("%c: Buyuk Harf\n", current);
            } else {
                printf("%c: Kucuk Harf\n", current);
            }
        } else if (isspace(current)) {
            printf("%c: Bosluk\n", current);
        } else {
            printf("%c: Sembol\n", current);
        }
    }

    return 0;
}


#include <stdio.h>

unsigned long long factorial(unsigned int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

int main() {
    unsigned int number;
    char choice;

    do {
        printf("\nBir pozitif tam say� girin: ");
        scanf("%u", &number);

        if (number < 0) {
            printf("Ge�ersiz giri�. L�tfen pozitif bir tam say� girin.\n");
            continue;
        }

        printf("%u say�s�n�n fakt�riyeli: %llu\n", number, factorial(number));

        printf("\nBa�ka bir say�n�n fakt�riyelini hesaplamak istiyor musunuz? (e/h): ");
        scanf(" %c", &choice);
    } while (choice == 'e' || choice == 'E');

    return 0;
}


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
        printf("\nBir pozitif tam sayý girin: ");
        scanf("%u", &number);

        if (number < 0) {
            printf("Geçersiz giriþ. Lütfen pozitif bir tam sayý girin.\n");
            continue;
        }

        printf("%u sayýsýnýn faktöriyeli: %llu\n", number, factorial(number));

        printf("\nBaþka bir sayýnýn faktöriyelini hesaplamak istiyor musunuz? (e/h): ");
        scanf(" %c", &choice);
    } while (choice == 'e' || choice == 'E');

    return 0;
}


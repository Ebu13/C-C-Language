#include <stdio.h>

// Recursive factorial calculation function
unsigned long long factorial(unsigned int n) {
    // Base case: Return 1 if factorial is 0 or 1
    if (n == 0 || n == 1)
        return 1;

    // Recursive case: n * (n-1)!
    return n * factorial(n - 1);
}

int main() {
    unsigned int number;
    char choice;

    do {
        printf("\nEnter a number: ");
        scanf("%u", &number);
        printf("factorial of %u: %llu\n", number,factorial(number));

        printf("\nDo you want to continue? (y/n):");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    return 0;
}

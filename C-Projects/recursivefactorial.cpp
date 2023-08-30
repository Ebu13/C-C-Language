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
        printf("\nEnter a positive integer: ");
        scanf("%u", &number);

        if (number < 0) {
            printf("Invalid input. Please enter a positive integer.\n");
            continue;
        }

        printf("Factorial of %u: %llu\n", number, factorial(number));

        printf("\nDo you want to calculate the factorial of another number? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
/*
This program calculates the factorial of a given number using recursion.
The user is prompted to enter a positive integer, and the factorial of that number is calculated and displayed.
If the user enters a negative number, an error message is displayed and the program prompts for input again.
The program then asks the user if they want to calculate the factorial of another number.
If the user enters 'y' or 'Y', the program repeats the process.
Otherwise, the program exits.
*/

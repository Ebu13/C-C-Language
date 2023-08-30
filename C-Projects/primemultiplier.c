#include <stdio.h>
#include <math.h>

void calculatePrimeFactors(int n) {
	int i;
    if (n < 0) {
        printf("You entered a negative number. Please enter a positive number.\n");
        return;
    }

    // Finding prime factors up to 2
    while (n % 2 == 0) {
        printf("2 ");
        n = n / 2;
    }

    // Checking odd numbers starting from 3
    for (i = 3; i <= sqrt(n); i = i + 2) {
        while (n % i == 0) {
            printf("%d ", i);
            n = n / i;
        }
    }

    // If there is a remaining prime factor (n should be a prime)
    if (n > 2) {
        printf("%d", n);
    }
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Prime factors: ");
    calculatePrimeFactors(num);

    return 0;
}


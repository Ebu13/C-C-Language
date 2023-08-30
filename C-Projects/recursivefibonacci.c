#include <stdio.h>

// Function to calculate the Fibonacci series
unsigned long long fibonacci(int n) {
    if (n <= 1)
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

// Function to print the Fibonacci series up to a certain element
void printFibonacciSeries(int n) {
	int i;
    printf("Fibonacci series up to element %d:\n", n);
    for (i = 0; i < n; i++) {
        printf("%llu ", fibonacci(i));
    }
    printf("\n");
}

int main() {
    int element;
    printf("Enter the element up to which the Fibonacci series should be printed: ");
    if (scanf("%d", &element) != 1 || element < 0) {
        printf("Invalid input. Please enter a non-negative integer.\n");
        return 1;
    }
    printFibonacciSeries(element);

    return 0;
}


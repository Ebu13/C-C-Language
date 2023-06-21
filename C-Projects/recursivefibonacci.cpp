#include <stdio.h>

// Function to calculate the Fibonacci series
int fibonacci(int n) {
    if (n <= 1)
        return n;
    else
        return fibonacci(n-1) + fibonacci(n-2);
}

// Function to print the Fibonacci series up to a certain element
void printFibonacciSeries(int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
}

int main() {
    int element;
    printf("Up to which element of the Fibonacci series should be printed? ");
    scanf("%d", &element);
    printFibonacciSeries(element);

    return 0;
}


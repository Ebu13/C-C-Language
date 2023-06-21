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
    
    printf("Enter a number: ");
    scanf("%u", &number);
    
    // Calculate factorial and print the result
    printf("Factorial: %llu\n", factorial(number));
    
    return 0;
}


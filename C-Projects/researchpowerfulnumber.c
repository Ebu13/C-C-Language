#include <stdio.h>

// Function to calculate factorial of a number
long long int factorial(int number) {
    if (number < 0) {
        printf("Error: Factorial of a negative number is undefined.\n");
        return -1;
    }
    
    long long int product = 1;
    int i;
    
    for (i = number; i > 0; i--) {
        product = product * i;
    }
    
    return product;
}

int main() {
    int inputNumber, originalNumber;
    
    printf("Enter a number: ");
    if (scanf("%d", &inputNumber) != 1) {
        printf("Error: Invalid input.\n");
        return 1;
    }
    originalNumber = inputNumber;
    
    int remainder;
    long long int factorialSum = 0;
    
    // Calculate the sum of factorials of digits
    while (inputNumber > 0) {
        remainder = inputNumber % 10;
        inputNumber = inputNumber / 10;
        
        long long int digitFactorial = factorial(remainder);
        if (digitFactorial == -1) {
            return 1;
        }
        printf("%d! = %lld \n", remainder, digitFactorial);
        factorialSum += digitFactorial;
    }
    
    printf("Sum = %lld \n", factorialSum);
    
    // Check if the number is a strong number
    if (factorialSum == originalNumber)
        printf("It is a strong number.\n");
    else
        printf("It is not a strong number.\n");
    
    return 0;
}


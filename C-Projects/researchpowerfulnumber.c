#include <stdio.h>
//A strong number is a number where the sum of the factorials of its digits 
//is equal to the number itself. In other words, if we take each digit of the number, 
//calculate the factorial of that digit, and then add up all these factorials, 
//the resulting sum will be equal to the original number.

// Function to calculate factorial of a number
int factorial(int number) {
    int product = 1;
    int i;
    
    for (i = number; i > 0; i--) {
        product = product * i;
    }
    
    return product;
}

int main() {
    int number, originalNumber;
    
    printf("Enter a number: ");
    scanf("%d", &number);
    originalNumber = number;
    
    int remainder;
    int sum = 0;
    
    // Calculate the sum of factorials of digits
    while (number > 0) {
        remainder = number % 10;
        number = number / 10;
        
        int digitFactorial = factorial(remainder);
        printf("%d! = %d \n", remainder, digitFactorial);
        sum += digitFactorial;
    }
    
    printf("Sum = %d \n", sum);
    
    // Check if the number is a strong number
    if (sum == originalNumber)
        printf("It is a strong number.\n");
    else
        printf("It is not a strong number.\n");
    
    return 0;
}


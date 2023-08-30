#include <stdio.h>
#include <stdbool.h>

// Function to calculate the sum of array elements
int calculateSum(int power, int array[]) {
    // Calculate the number of elements as the power of 2
    int elementCount = 1 << power;
    int sum = 0, i;

    for (i = 0; i < elementCount; i++) {
        // Check if array elements are positive
        if (array[i] <= 0) {
            printf("Array elements must be positive!\n");
            return 0;
        }
        sum += array[i];
    }

    return sum;
}

int main() {
    int power, i;
    printf("What should be the power of 2 for the number of array elements? ");
    scanf("%d", &power);

    int elementCount = 1 << power;
    int array[elementCount];

    printf("Enter %d elements:\n", elementCount);
    for (i = 0; i < elementCount; i++) {
        scanf("%d", &array[i]);
    }

    int sum = calculateSum(power, array);
    printf("Sum of the array elements: %d\n", sum);

    return 0;
}


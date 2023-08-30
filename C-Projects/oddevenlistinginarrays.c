#include <stdio.h>

#define MAX_NUM_OF_ELEMENTS 100

int main() {
    int index = 0;
    int numOfElements = 0;
    int numbers[MAX_NUM_OF_ELEMENTS];

    printf("How many numbers will you enter (up to %d): ", MAX_NUM_OF_ELEMENTS);
    scanf("%d", &numOfElements);

    if (numOfElements <= 0 || numOfElements > MAX_NUM_OF_ELEMENTS) {
        printf("Invalid number of elements.\n");
        return 0;
    }

    for (index = 0; index < numOfElements; index++) {
        printf("Enter %dth number: ", index + 1);
        if (scanf("%d", &numbers[index]) != 1) {
            printf("Invalid input. Please enter a valid number.\n");
            index--;
            continue;
        }

        if (numbers[index] < 0) {
            printf("Do not enter negative numbers.\n");
            index--;
            continue;
        }
    }

    int evenCount = 0;
    int oddCount = 0;
    int evenNumbers[MAX_NUM_OF_ELEMENTS];
    int oddNumbers[MAX_NUM_OF_ELEMENTS];

    for (index = 0; index < numOfElements; index++) {
        if (numbers[index] % 2 == 0) {
            evenNumbers[evenCount] = numbers[index];
            evenCount++;
        } else {
            oddNumbers[oddCount] = numbers[index];
            oddCount++;
        }
    }

    printf("\nOdd Numbers: ");
    if (oddCount == 0) {
        printf("{}");
    } else {
        printf("{");
        for (index = 0; index < oddCount; index++) {
            printf("%d", oddNumbers[index]);
            if (index < oddCount - 1) {
                printf(",");
            }
        }
        printf("}");
    }

    printf("\nEven Numbers: ");
    if (evenCount == 0) {
        printf("{}");
    } else {
        printf("{");
        for (index = 0; index < evenCount; index++) {
            printf("%d", evenNumbers[index]);
            if (index < evenCount - 1) {
                printf(",");
            }
        }
        printf("}");
    }

    return 0;
}

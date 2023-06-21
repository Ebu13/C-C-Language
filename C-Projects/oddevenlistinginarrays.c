#include <stdio.h>

int main() {
    int i = 0, z = 0, a = 0, b, w, c;

    // Prompt user to enter the number of elements
    printf("How many numbers will you enter: ");
    scanf("%d", &w);

    // Create an array with size w to store the numbers
    int Array[w];

    // Loop to read w numbers from the user
    while (i < w) {
        printf("Enter %dth number: ", i + 1);
        scanf("%d", &Array[i]);

        // Check if the number is negative, and prompt the user not to enter negative numbers
        if (Array[i] < 0) {
            printf("Do not enter negative numbers.\n");
            continue;
        }

        i++;
    }

    // Count the number of even and odd numbers
    for (i = 0; i < w; i++) {
        if (Array[i] % 2 == 0) {
            z++; // Increment the count of even numbers
        } else {
            a++; // Increment the count of odd numbers
        }
    }

    // Store the counts in separate variables (b and c) before modifying a and z
    b = z;
    c = a;

    // Create separate arrays to store odd and even numbers
    int odd[a], even[z];

    // Reset the counters
    a = 0;
    z = 0;

    // Loop to separate odd and even numbers into different arrays
    for (i = 0; i < w; i++) {
        if (Array[i] % 2 == 0) {
            even[z] = Array[i]; // Store the even number
            z++;
        } else {
            odd[a] = Array[i]; // Store the odd number
            a++;
        }
    }

    // Print the odd numbers
    if (c == 0) {
        printf("\n\nOdd Numbers: {}");
    } else {
        printf("\n\nOdd Numbers: {");
        for (a = 0; a < c; a++) {
            printf("%d", odd[a]);

            if (a < c - 1) {
                printf(",");
            }
        }
        printf("}");
    }

    // Print the even numbers
    if (b == 0) {
        printf("\n\nEven Numbers: {}");
    } else {
        printf("\n\nEven Numbers: {");
        for (z = 0; z < b; z++) {
            printf("%d", even[z]);

            if (z < b - 1) {
                printf(",");
            }
        }
        printf("}");
    }

    return 0;
}


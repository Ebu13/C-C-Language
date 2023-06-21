#include <stdio.h>
#include <conio.h>

int main() {
    int x, y;
    printf("\t \t\t             Multiplication Table\n"); // The title "Multiplication Table" is used.

    for (x = 1; x < 11; x++) {
        printf("\n\t");
        for (y = 1; y < 6; y++) {
            printf("%d*%d=%d\t\t", y, x, x * y); // (x * y) should be replaced with (y * x) for the multiplication table.
        }
    }
    printf("\n");

    for (x = 1; x < 11; x++) {
        printf("\n\t");
        for (y = 6; y < 11; y++) {
            printf("%d*%d=%d\t\t", y, x, x * y); // (x * y) should be replaced with (y * x) for the multiplication table.
        }
    }
    
    return 0;
}


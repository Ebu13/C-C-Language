#include <stdio.h>
int main() {
	int x, y;
	printf("\t \t\t             Multiplication Table\n"); // The title "Multiplication Table" is used.
	    // Print the first half of the multiplication table
	for (x = 1; x < 11; x++) {
	    printf("\n\t");
	    for (y = 1; y < 6; y++) {
	        printf("%d * %d = %d\t\t", y, x, y * x); // Multiply y by x instead of x by y
	    }
	}
	
	// Print the second half of the multiplication table
	printf("\n");
	for (x = 1; x < 11; x++) {
	    printf("\n\t");
	    for (y = 6; y < 11; y++) {
	        printf("%d * %d = %d\t\t", y, x, y * x); // Multiply y by x instead of x by y
	    }
	}
	
	return 0;
}
// This program prints a multiplication table 
//from 1 to 10. The table is divided into two halves for better readability.

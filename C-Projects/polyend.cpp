#include <stdio.h>
#include <stdlib.h>

struct term {
  int coefficient;
  int degree;
};

int constant_term(struct term *polynomial, int num_terms) {
  if (polynomial == NULL || num_terms <= 0)
    return 0;
  
  if (polynomial[0].degree == 0)
    return polynomial[0].coefficient;
  
  return constant_term(polynomial + 1, num_terms - 1);
}

int main() {
  struct term *polynomial;
  int num_terms, i;
  
  printf("Enter the number of polynomial terms: ");
  scanf("%d", &num_terms);
  
  // Memory allocation for polynomial terms
  polynomial = (struct term*) malloc(num_terms * sizeof(struct term));
  if (polynomial == NULL) {
    printf("Memory allocation failed. Exiting the program.\n");
    return 1;
  }
  
  printf("Enter the polynomial terms (coefficient degree):\n");
  for (i = 0; i < num_terms; i++) {
    scanf("%d %d", &(polynomial[i].coefficient), &(polynomial[i].degree));
  }
  
  int constant = constant_term(polynomial, num_terms);
  printf("Constant term: %d\n", constant);
  
  // Free allocated memory
  free(polynomial);
  
  return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct term {
    int coefficient;
    int degree;
};

// Polinom terimlerini kullanýcýdan al
void polynomial_input(struct term *polynomial, int num_terms) {
    printf("Polinom terimlerini girin (katsayi derece):\n");
    int i;
    for (i = 0; i < num_terms; i++) {
        printf("Terim %d: ", i + 1);
        scanf("%d %d", &(polynomial[i].coefficient), &(polynomial[i].degree));
    }
}

// Polinomu ekrana yazdýr
void polynomial_output(struct term *polynomial, int num_terms) {
    printf("Girilen Polinom:\n");
    int i;
    for (i = 0; i < num_terms; i++) {
        if (polynomial[i].degree == 0) {
            printf("%d ", polynomial[i].coefficient);
        } else {
            printf("%dx^%d ", polynomial[i].coefficient, polynomial[i].degree);
        }
        if (i != num_terms - 1) // Son terimden sonra '+' iþareti koyma
            printf("+ ");
    }
    printf("\n");
}


// Polinomun sabit terimini hesapla
int constant_term(struct term *polynomial, int num_terms) {
    if (polynomial == NULL || num_terms <= 0)
        return 0;

    if (polynomial[0].degree == 0)
        return polynomial[0].coefficient;

    return constant_term(polynomial + 1, num_terms - 1);
}

int main() {
	
	//Örnek kullaným aþaðýdaki gibidir.
	/*
	Polinomunuzun kac terim icerecegini girin: 4
	Polinom terimlerini girin (katsayi derece):
	Terim 1: 3 3
	Terim 2: -5 2
	Terim 3: 8 1
	Terim 4: 4 0
	Girilen Polinom:
	3x^3 + -5x^2 + 8x^1 + 4
	Polinomun sabit terimi: 4
	*/
    struct term *polynomial;
    int num_terms;

    printf("Polinomunuzun kac terim icerecegini girin: ");
    scanf("%d", &num_terms);

    // Bellek tahsisi
    polynomial = (struct term*) malloc(num_terms * sizeof(struct term));
    if (polynomial == NULL) {
        printf("Bellek tahsisi basarisiz. Program sonlandiriliyor.\n");
        return 1;
    }

    // Polinom terimlerini al
    polynomial_input(polynomial, num_terms);

    // Girilen polinomu ekrana yazdýr
    polynomial_output(polynomial, num_terms);

    // Sabit terimi hesapla ve ekrana yazdýr
    int constant = constant_term(polynomial, num_terms);
    printf("Polinomun sabit terimi: %d\n", constant);

    // Ayrýlan belleði serbest býrak
    free(polynomial);

    return 0;
}


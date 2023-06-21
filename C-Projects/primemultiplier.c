#include <stdio.h>

void printPrimeFactors(int n) {
// Finding all powers of 2
while (n % 2 == 0) {
printf("2 ");
n = n / 2;
}
int i;
// Finding all powers of 3 and subsequent odd prime factors
for (i = 3; i * i <= n; i = i + 2) {
while (n % i == 0) {
printf("%d ", i);
n = n / i;
}
}
// If there is a remaining prime factor (n should be a prime)
if (n > 2) {
    printf("%d", n);
}
}

int main() {
int num;
printf("Enter a number: ");
scanf("%d", &num);

printf("Prime factors: ");
printPrimeFactors(num);

return 0;
}

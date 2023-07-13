#include <stdio.h>

struct terim {
  int katsayi;
  int derece;
};

int sabit_sayi(struct terim *polinom) {
  if (polinom == NULL)
    return 0;
  
  if (polinom->derece == 0)
    return polinom->katsayi;
  
  return sabit_sayi(polinom + 1);
}

int main() {
  struct terim polinom[100];
  int n, i;
  
  printf("Polinom terim sayisini girin: ");
  scanf("%d", &n);
  
  printf("Polinom terimlerini girin (katsayi derece):\n");
  for (i = 0; i < n; i++) {
    scanf("%d %d", &(polinom[i].katsayi), &(polinom[i].derece));
  }
  
  int sabit = sabit_sayi(polinom);
  printf("Sabit sayi: %d\n", sabit);
  
  return 0;
}

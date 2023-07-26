#include <stdio.h>

int toplamHesapla(int kuvvet, int dizi[]) {
    // Eleman sayisini 2'nin kuvveti yapma kontrolu
    int elemanSayisi = 1 << kuvvet;
    int i, toplam = 0;

    for (i = 0; i < elemanSayisi; i++) {
        if (dizi[i] <= 0) {
            printf("Dizi elemanlari pozitif olmalidir!\n");
            return 0;
        }
        toplam += dizi[i];
    }

    return toplam;
}

int main() {
    int kuvvet, i;
    printf("Dizinin eleman sayisi 2'nin kuvveti olacak sekilde kuvvet kac olacak? ");
    scanf("%d", &kuvvet);

    int elemanSayisi = 1 << kuvvet;
    int dizi[elemanSayisi];

    printf("%d eleman girin:\n", elemanSayisi);
    for (i = 0; i < elemanSayisi; i++) {
        scanf("%d", &dizi[i]);
    }

    int toplam = toplamHesapla(kuvvet, dizi);
    printf("Dizideki sayilarin toplami: %d\n", toplam);

    return 0;
}


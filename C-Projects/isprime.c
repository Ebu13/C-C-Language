#include <stdio.h>

// Bir say�n�n asal olup olmad���n� kontrol eden fonksiyon
int asalMi(int num) {
    if (num <= 1) {
        return 0;  // 0 ve 1 asal say� de�ildir.
    }
    int i;
    for (i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;  // B�len bulundu, asal de�il.
        }
    }

    return 1;  // B�len bulunamad�, asal say�d�r.
}

int main() {
    int num;

    printf("Bir sayi giriniz: ");
    scanf("%d", &num);

    if (asalMi(num)) {
        printf("%d bir asal sayidir.\n", num);
    } else {
        printf("%d bir asal sayi degildir.\n", num);
    }

    return 0;
}


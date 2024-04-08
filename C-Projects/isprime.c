#include <stdio.h>

// Bir sayýnýn asal olup olmadýðýný kontrol eden fonksiyon
int asalMi(int num) {
    if (num <= 1) {
        return 0;  // 0 ve 1 asal sayý deðildir.
    }
    int i;
    for (i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;  // Bölen bulundu, asal deðil.
        }
    }

    return 1;  // Bölen bulunamadý, asal sayýdýr.
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


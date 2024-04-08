#include <stdio.h>

// Bir y�l�n art�k y�l olup olmad���n� kontrol eden fonksiyon
int artikYilMi(int yil) {
    if ((yil % 4 == 0 && yil % 100 != 0) || yil % 400 == 0) {
        return 1;
    }
    return 0;
}

// Verilen tarihe kadar ge�en toplam g�nleri hesaplayan fonksiyon
int toplamGunHesapla(int gun, int ay, int yil) {
    int ayGunleri[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int toplamGun = 0, i;
    
    // �nceki y�llar�n katk�lar�n� ekle
    for (i = 1; i < yil; i++) {
        toplamGun += 365 + artikYilMi(i);
    }
    
    // �nceki aylar�n katk�lar�n� ekle
    for (i = 1; i < ay; i++) {
        toplamGun += ayGunleri[i];
    }
    
    // Girilen g�n� ekle
    toplamGun += gun;
    
    // Art�k y�l� d�zelt
    if (ay > 2 && artikYilMi(yil)) {
        toplamGun += 1;
    }
    
    return toplamGun;
}

// Haftan�n g�n�n� bulan fonksiyon
void gunuBul(int toplamGun) {
    char* haftaninGunleri[] = {"Pazar", "Pazartesi", "Sal�", "�ar�amba", "Per�embe", "Cuma", "Cumartesi"};
    int haftaninGunu = toplamGun % 7;
    printf("Haftanin gunu: %s\n", haftaninGunleri[haftaninGunu]);
}

int main() {
    int gun, ay, yil;
    char cikisSecenegi;
    
    while (1) {
        printf("Tarihi girin:\n");
        printf("Gun: "); scanf("%d", &gun);
        printf("Ay: "); scanf("%d", &ay);
        printf("Yll: "); scanf("%d", &yil);
        
        int toplamGun = toplamGunHesapla(gun, ay, yil);
        gunuBul(toplamGun);
        
        printf("Cikmak istiyor musunuz? (e)(Devam Etmek icin herhangi bir harf veya sayi gir.): ");
        scanf(" %c", &cikisSecenegi);
        
        if (cikisSecenegi == 'e' || cikisSecenegi == 'E') {
            break;
        }
    }
    
    return 0;
}


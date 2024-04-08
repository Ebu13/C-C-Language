#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAKSIMUM_DOSYA_ADI_UZUNLUGU 100

// Kullan�c�dan dosya ad�n� almak i�in fonksiyon
void dosyaAdiniAl(char *dosyaAdi) {
    printf("Dosyanin adini girin: ");
    scanf("%s", dosyaAdi);
}

// Bir dosya olu�turmak i�in fonksiyon
void dosyaOlustur() {
    char dosyaAdi[MAKSIMUM_DOSYA_ADI_UZUNLUGU];
    dosyaAdiniAl(dosyaAdi);

    // Dosyay� olu�turma ve a�ma
    FILE *dosya = fopen(dosyaAdi, "w");
    if (dosya == NULL) {
        printf("Dosya olusturulamadi.\n");
        return;
    }

    printf("Dosya olusturuldu: %s\n", dosyaAdi);
    fclose(dosya);
}

// Bir dosyay� silmek i�in fonksiyon
void dosyaSil() {
    char dosyaAdi[MAKSIMUM_DOSYA_ADI_UZUNLUGU];
    dosyaAdiniAl(dosyaAdi);

    // Dosyay� silme
    if (remove(dosyaAdi) == 0) {
        printf("Dosya silindi: %s\n", dosyaAdi);
    } else {
        printf("Dosya silinemedi.\n");
    }
}

// Bir dosyay� okumak i�in fonksiyon
void dosyayiOku() {
    char dosyaAdi[MAKSIMUM_DOSYA_ADI_UZUNLUGU];
    dosyaAdiniAl(dosyaAdi);

    // Dosyay� a�ma ve sat�r sat�r okuma
    FILE *dosya = fopen(dosyaAdi, "r");
    if (dosya == NULL) {
        printf("Dosya bulunamadi.\n");
        return;
    }

    char satir[100];
    printf("Dosya icerigi:\n");
    while (fgets(satir, sizeof(satir), dosya) != NULL) {
        printf("%s", satir);
    }

    fclose(dosya);
}

// Bir dosyaya yazmak i�in fonksiyon
void dosyayaYaz() {
    char dosyaAdi[MAKSIMUM_DOSYA_ADI_UZUNLUGU];
    dosyaAdiniAl(dosyaAdi);

    // Dosyay� a�ma ve veri yazma
    FILE *dosya = fopen(dosyaAdi, "a+");
    if (dosya == NULL) {
        printf("Dosya bulunamadi.\n");
        return;
    }

    char veri[100];
    printf("Dosyaya yazilacak veriyi girin: ");
    scanf(" %[^\n]s", veri);

    fprintf(dosya, "%s\n", veri);
    printf("Veri dosyaya yazildi.\n");

    fclose(dosya);
}

// Bir dosyan�n i�eri�ini tamamen silmek i�in fonksiyon
void dosyaIceriginiSil() {
    char dosyaAdi[MAKSIMUM_DOSYA_ADI_UZUNLUGU];
    dosyaAdiniAl(dosyaAdi);

    // Dosyay� a�ma ve i�eri�ini temizleme
    FILE *dosya = fopen(dosyaAdi, "w");
    // w yeniden yazma modunda oldu�u i�in i�ini bo�alt�p a��yor. w yerine a olsayd�
	// ekleme modunda olurdu. 
    if (dosya == NULL) {
        printf("Dosya bulunamadi.\n");
        return;
    }
    printf("Dosyanin icerigi tamamen silindi.\n");
    fclose(dosya);
}

int main() {
    int secim;
    printf("Dosya adini dosya.txt formatinda girin.\n");
    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Dosya Olustur\n");
        printf("2. Dosya Sil\n");
        printf("3. Dosyayi Oku\n");
        printf("4. Dosyaya Yaz\n");
        printf("5. Dosya Icerigini Sil\n");
        printf("6. Cikis\n");
        printf("Bir secim yapin: ");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                dosyaOlustur();
                break;
            case 2:
                dosyaSil();
                break;
            case 3:
                dosyayiOku();
                break;
            case 4:
                dosyayaYaz();
                break;
            case 5:
                dosyaIceriginiSil();
                break;
            case 6:
                printf("Programdan cikiliyor.\n");
                exit(0);
            default:
                printf("Gecersiz secim. L�tfen tekrar deneyin.\n");
        }
    }

    return 0;
}


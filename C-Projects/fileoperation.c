#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAKSIMUM_DOSYA_ADI_UZUNLUGU 100

// Kullanýcýdan dosya adýný almak için fonksiyon
void dosyaAdiniAl(char *dosyaAdi) {
    printf("Dosyanin adini girin: ");
    scanf("%s", dosyaAdi);
}

// Bir dosya oluþturmak için fonksiyon
void dosyaOlustur() {
    char dosyaAdi[MAKSIMUM_DOSYA_ADI_UZUNLUGU];
    dosyaAdiniAl(dosyaAdi);

    // Dosyayý oluþturma ve açma
    FILE *dosya = fopen(dosyaAdi, "w");
    if (dosya == NULL) {
        printf("Dosya olusturulamadi.\n");
        return;
    }

    printf("Dosya olusturuldu: %s\n", dosyaAdi);
    fclose(dosya);
}

// Bir dosyayý silmek için fonksiyon
void dosyaSil() {
    char dosyaAdi[MAKSIMUM_DOSYA_ADI_UZUNLUGU];
    dosyaAdiniAl(dosyaAdi);

    // Dosyayý silme
    if (remove(dosyaAdi) == 0) {
        printf("Dosya silindi: %s\n", dosyaAdi);
    } else {
        printf("Dosya silinemedi.\n");
    }
}

// Bir dosyayý okumak için fonksiyon
void dosyayiOku() {
    char dosyaAdi[MAKSIMUM_DOSYA_ADI_UZUNLUGU];
    dosyaAdiniAl(dosyaAdi);

    // Dosyayý açma ve satýr satýr okuma
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

// Bir dosyaya yazmak için fonksiyon
void dosyayaYaz() {
    char dosyaAdi[MAKSIMUM_DOSYA_ADI_UZUNLUGU];
    dosyaAdiniAl(dosyaAdi);

    // Dosyayý açma ve veri yazma
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

// Bir dosyanýn içeriðini tamamen silmek için fonksiyon
void dosyaIceriginiSil() {
    char dosyaAdi[MAKSIMUM_DOSYA_ADI_UZUNLUGU];
    dosyaAdiniAl(dosyaAdi);

    // Dosyayý açma ve içeriðini temizleme
    FILE *dosya = fopen(dosyaAdi, "w");
    // w yeniden yazma modunda olduðu için içini boþaltýp açýyor. w yerine a olsaydý
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
                printf("Gecersiz secim. Lütfen tekrar deneyin.\n");
        }
    }

    return 0;
}


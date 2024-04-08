#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;
    FILE *filePtr = fopen("test.txt", "a"); 
    //Ekleme modunda açýyor.Kaldýðý yerden devam ediyor en son karakterden.
    if (filePtr == NULL) {
        printf("Dosya Hatasý.\n"); 
        return 1;
    }
    //Satýr atladýktan sonra ilk satýra "Dosya Ýþlemleri" yazdýrdý ve alt satýra geçti.
    fprintf(filePtr, "%s", "\nDosya Ýþlemleri");
    
    // 1 den 5 e kadarki tüm sayýlarý alt alta yazdýrýyor.
    for (i = 0; i < 5; i++) {
        fprintf(filePtr, "\n%d", i + 1); 
    }
    fclose(filePtr);
    // txt dosyasýnda çýkýldý.
    printf("Eklendi.\n");
    // Konsol ekranýna "Eklendi" mesajý verildi
    return 0;
}

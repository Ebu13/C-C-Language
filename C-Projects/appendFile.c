#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;
    FILE *filePtr = fopen("test.txt", "a"); 
    //Ekleme modunda a��yor.Kald��� yerden devam ediyor en son karakterden.
    if (filePtr == NULL) {
        printf("Dosya Hatas�.\n"); 
        return 1;
    }
    //Sat�r atlad�ktan sonra ilk sat�ra "Dosya ��lemleri" yazd�rd� ve alt sat�ra ge�ti.
    fprintf(filePtr, "%s", "\nDosya ��lemleri");
    
    // 1 den 5 e kadarki t�m say�lar� alt alta yazd�r�yor.
    for (i = 0; i < 5; i++) {
        fprintf(filePtr, "\n%d", i + 1); 
    }
    fclose(filePtr);
    // txt dosyas�nda ��k�ld�.
    printf("Eklendi.\n");
    // Konsol ekran�na "Eklendi" mesaj� verildi
    return 0;
}

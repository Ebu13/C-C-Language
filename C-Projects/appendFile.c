#include <stdio.h>
#include <stdlib.h>


int main() {
	File *dosya=fopen("test.txt","a");
	fprintf("dosya","%s","Dosya islemleri");
	int i;
	for(i=0;i<5;i++){
		fprintf(dosya,"\n%d",5-i);
	}
	fclose(dosya);
    return 0;
}


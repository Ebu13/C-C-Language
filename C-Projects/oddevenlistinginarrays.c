#include <stdio.h>

int main() {
    int i = 0, z = 0, a = 0, b, w, c;
    
    printf("How many numbers will you enter: ");
    scanf("%d", &w);
    
    int Array[w];
    
    while (i < w) {
        printf("Enter %dth number: ", i + 1);
        scanf("%d", &Array[i]);
        
        if (Array[i] < 0) {
            printf("Do not enter negative numbers.\n");
            continue;
        }
        
        i++;
    }
    
    for (i = 0; i < w; i++) {
        if (Array[i] % 2 == 0) {
            z++;
        } else {
            a++;
        }
    }
    
    b = z;
    c = a;
    int odd[a], even[z];
    a = 0;
    z = 0;
    
    for (i = 0; i < w; i++) {
        if (Array[i] % 2 == 0) {
            even[z] = Array[i];
            z++;
        } else {
            odd[a] = Array[i];
            a++;
        }
    }
    
    if (c == 0) {
        printf("\n\nOdd Numbers: {}");
    } else {
        printf("\n\nOdd Numbers: {");
        for (a = 0; a < c; a++) {
            printf("%d", odd[a]);
            
            if (a < c - 1) {
                printf(",");
            }
        }
        printf("}");
    }
    
    if (b == 0) {
        printf("\n\nEven Numbers: {}");
    } else {
        printf("\n\nEven Numbers: {");
        for (z = 0; z < b; z++) {
            printf("%d", even[z]);
            
            if (z < b - 1) {
                printf(",");
            }
        }
        printf("}");
    }
    
    return 0;
}


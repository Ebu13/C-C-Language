#include <stdio.h>

// Bubble Sort algorithm
void bubbleSort(int arr[], int n) {
    int i, j, k;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swapping elements
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        // Printing the state of the array at each step
        printf("Step %d: ", i+1);
        for (k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
}

// Selection Sort algorithm
void selectionSort(int arr[], int n) {
    int i, j, min_idx, k;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        // Swapping the minimum element with the i-th element
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
        // Printing the state of the array at each step
        printf("Step %d: ", i+1);
        for (k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
}

// Insertion Sort algorithm
void insertionSort(int arr[], int n) {
    int i, key, j, k;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key;
        // Printing the state of the array at each step
        printf("Step %d: ", i);
        for (k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
}

int main() {
    int arr[100];
    int n, i;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the numbers:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int choice;
    printf("\nSelect the sorting method:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    scanf("%d", &choice);
    
    printf("\nArray steps:\n");
    switch(choice) {
        case 1:
            bubbleSort(arr, n);
            break;
        case 2:
            selectionSort(arr, n);
            break;
        case 3:
            insertionSort(arr, n);
            break;
        default:
            printf("Invalid choice!");
    }
    
    printf("\nSorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}


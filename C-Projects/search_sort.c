#include <stdio.h>
#include <stdlib.h>

// Linear Search
int linearSearch(int array[], int N, int target) {
    int i;
    int index = -1;
    for (i = 0; i < N; i++) {
        if (array[i] == target) {
            return i;
        }
    }
    return index; // or return -1;
}

// Binary Search
int binarySearch(int array[], int N, int target) {
    int middle, left = 0, right = N - 1;
    while (left <= right) {
        middle = (left + right) / 2; // find the index of the middle element of the array
        if (target == array[middle])
            return middle; // return to the main function if the target number is found
        else if (target > array[middle])
            left = middle + 1; // if the target number is greater than the middle number, shift the left index (look to the right of the middle)
        else
            right = middle - 1; // if the target number is smaller than the middle number, shift the right index (look to the left of the middle)
    }
    return -1; // return -1 if not found
}

// Bubble Sort
void bubbleSort(int array[], int N) {
    int i, j;
    int temp;
    for (i = 0; i < N; i++) { // Number of passes
        for (j = 0; j < N - 1 - i; j++) {
            if (array[j] > array[j + 1]) { // Compare each number with the next one
                // Swap if greater
                temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
            }
        }
    }
}

// Selection Sort
void selectionSort(int array[], int N) {
    int i, j;
    int temp;
    for (i = 0; i < N; i++) { // Number of passes (size of the array)
        // Find the index of the smallest element
        int minIndex = i;
        for (j = i + 1; j < N; j++) {
            if (array[j] < array[minIndex])
                minIndex = j;
        }
        // Swap the smallest with the i-th element
        temp = array[minIndex];
        array[minIndex] = array[i];
        array[i] = temp;
    }
}

int main() {
    int N;
    printf("Enter the size of the array: ");
    scanf("%d", &N);
    
    if (N <= 0 || N > 100) {
        printf("Invalid array size. Please enter a size between 1 and 100.\n");
        return 0;
    }
    
    int* array = (int*)malloc(N * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 0;
    }
    
    printf("Enter the elements of the array:\n");
    int i;
    for (i = 0; i < N; i++) {
        scanf("%d", &array[i]);
    }
    
    printf("Choose an option:\n");
    printf("1. Linear Search\n");
    printf("2. Binary Search\n");
    printf("3. Bubble Sort\n");
    printf("4. Selection Sort\n");
    int option;
    scanf("%d", &option);
    
    switch (option) {
        case 1:
            printf("Enter the number to search for: ");
            int target;
            scanf("%d", &target);
            int result = linearSearch(array, N, target);
            if (result >= 0) {
                printf("The number %d is found at position %d.\n", target, result + 1);
            } else {
                printf("The number %d is not found.\n", target);
            }
            break;
        case 2:
            printf("Enter the number to search for: ");
            int target2;
            scanf("%d", &target2);
            bubbleSort(array, N);
            int result2 = binarySearch(array, N, target2);
            if (result2 >= 0) {
                printf("The number %d is found at position %d.\n", target2, result2 + 1);
            } else {
                printf("The number %d is not found.\n", target2);
            }
            break;
        case 3:
            bubbleSort(array, N);
            printf("The array has been sorted using Bubble Sort.\n");
            printf("Sorted array: ");
            for (i = 0; i < N; i++) {
                printf("%d ", array[i]);
            }
            printf("\n");
            break;
        case 4:
            selectionSort(array, N);
            printf("The array has been sorted using Selection Sort.\n");
            printf("Sorted array: ");
            for (i = 0; i < N; i++) {
                printf("%d ", array[i]);
            }
            printf("\n");
            break;
        default:
            printf("Invalid option.\n");
            break;
    }
    
    free(array);
    
    return 0;
}

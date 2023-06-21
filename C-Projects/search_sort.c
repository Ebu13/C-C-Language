#include <stdio.h>

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
    
    int array[N];
    printf("Enter the elements of the array:\n");
    int i;
    for (i = 0; i < N; i++) {
        scanf("%d", &array[i]);
    }
    
    int target;
    printf("Enter the number to search for: ");
    scanf("%d", &target);
    
    int result = linearSearch(array, N, target);
    if (result >= 0) {
        printf("The number %d is found at position %d.\n", target, result + 1);
    } else {
        printf("The number %d is not found.\n", target);
    }
    
    return 0;
}

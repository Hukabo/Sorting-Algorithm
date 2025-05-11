#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define COUNT 10

void countingSort(int arr[], int n, int exp) {

    int* count = (int*)malloc(sizeof(int) * COUNT);
    int* output = (int*)calloc(n,sizeof(int));

    for (int i = 0; i < n; i++) {
        int pos = (arr[i] / exp) % 10;
        count[pos]++;
    }

    for (int i = 1; i < COUNT; i++)
        count[i] += count[i-1];
    
    for (int i = n-1; i >= 0; i--) {
        int pos = (arr[i] / exp) % 10;
        output[--count[pos]] = arr[i];
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n) {
    int max = arr[0];
    int exp = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    while (max / exp > 0) {
        countingSort(arr, n, exp);
        exp *= 10;
    }
}

int main() {

    int arr[] = {19, 23, 89, 41, 803, 54, 773, 11};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Before Sorted: ");

    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    radixSort(arr, size);

    printf("After Sorted: ");

    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
    
    return 0;
}
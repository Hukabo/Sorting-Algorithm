#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 10

void insertionSort(float arr[], int n) {
    for (int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void d_bucketsort(int arr[], int n) { // 정수형 버킷 정렬
    int max = arr[0]; // get the maximum element in the array

    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i]; // max = 87
    }
    int b[max], i; // b[87]

    for (int i = 0; i <= max; i++) {
        b[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        b[arr[i]]++;
    } // b[12] = 1, b[45] = 1, b[33] = 1, b[87] = 1, b[56] = 1, b[9] = 1, b[11] = 1, b[7] = 1, b[67] = 1
    for (int i = 0, j = 0; i <= max; i++) {
        while(b[i] > 0) {
            arr[j++] = i;
            b[i]--;
        }
    }
}

void f_bucketSort(float arr[], int n) { // 실수형 버킷 정렬
    float* buckets[BUCKET_SIZE];
    int bucketCounts[BUCKET_SIZE] = {0};

    for (int i = 0; i < BUCKET_SIZE; i++) {
        buckets[i] = (float*)malloc(sizeof(float) * n);
    }

    for (int i = 0; i < n; i++) {
        int bucketIndex = (int)(arr[i] * BUCKET_SIZE);
        buckets[bucketIndex][bucketCounts[bucketIndex]++] = arr[i];
    }

    for (int i = 0; i < BUCKET_SIZE; i++) {
        insertionSort(buckets[i], bucketCounts[i]);
    }

    int idx = 0;
    for (int i = 0; i < BUCKET_SIZE; i++) {
        for (int j = 0; j < bucketCounts[i]; j++) {
            arr[idx++] = buckets[i][j];
        }
    }

    for (int i = 0; i < BUCKET_SIZE; i++) {
        free(buckets[i]);
    }
}

int main() {
    int a[] = {12, 45, 33, 87, 56, 9, 11, 7, 67};
    int n = sizeof(a) / sizeof(a[0]);

    printf("Before sotring array elements are: \n");

    for (int i = 0; i < n; ++i) 
        printf("%d ", a[i]);
    
    d_bucketsort(a, n);

    printf("\nAfter sorting array elements are: \n");

    for (int i = 0; i < n; ++i)
        printf("%d ", a[i]);

    float arr[] = {0.23, 0.45, 0.12, 0.89, 0.33, 0.67, 0.99, 0.01, 0.13, 0.64};
    n = sizeof(arr) / sizeof(arr[0]);

    printf("\nBefore Sorting:\n");
    for (int i = 0; i < n; i++)
        printf("%.2f ",arr[i]);
    printf("\n");

    f_bucketSort(arr, n);

    printf("After Sorting:\n");
    for (int i = 0; i < n; i++)
        printf("%.2f ", arr[i]);
    printf("\n");

    return 0;
}
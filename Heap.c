#include <stdio.h>

void swap(int arr[], int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void heapify(int arr[], int size, int i) {
    int largest = i;
    int left = i*2 + 1;
    int right = i*2 + 2;

    if (left < size && arr[left] > arr[largest])
        largest = left;
    if (right < size && arr[right] > arr[largest])
        largest = right;
    
    if (largest != i) { // if largest was changed.
        swap(arr, largest, i);
        heapify(arr, size, largest);
    }
}

void heapSort(int arr[], int n) {
    // Step 1: Build Max Heap
    for (int i = n/2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Step 2: Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--) {
        swap(arr, 0, i); // Move current max to end
        heapify(arr, i, 0); // Heapify reduced heap
    }
}

int main() {
        int arr[] = {20, 10, 15, 5, 7, 30, 2};
        int n = sizeof(arr) / sizeof(arr[0]);

        printf("Before Sorting: ");
        for (int i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");

        heapSort(arr, n);

        printf("After Sorting: ");
        for (int i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");

        return 0;
    }
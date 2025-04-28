#include <stdio.h>

void swap(int arr[], int i, int j) { // 배열 요소 위치 교환 함수
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void heapify(int arr[], int size, int i) {
    int largest = i;
    int left = (i * 2) + 1; // i의 왼쪽 자식
    int right = (i * 2) + 2; // i의 오른쪽 자식

    if(left < size && arr[left] > arr[largest])
        largest = left;
    if(right < size && arr[right] > arr[largest])
        largest = right;
    if(largest != i) {
        swap(arr, largest, i);
        heapify(arr, size, largest);
    }
}

void buildMaxHeap(int arr[], int size) {
    // i를 (size/2)-1부터 하는 이유 : 부모를 포함하여 배열의 끝에 있는 자식부터 탐색하기 위해
    for(int i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, size, i);
    }
}

int main() {
    int arr[] = {3, 10, 4, 5, 1, 7, 8};
    
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Before Heapify : ");
    
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    buildMaxHeap(arr, size);

    printf("Max Heap : ");
    
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
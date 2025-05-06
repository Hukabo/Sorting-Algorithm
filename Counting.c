#include <stdio.h>
#include <stdlib.h>

void countingSort(int arr[], int n) {

    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if(arr[i] > max)
            max = arr[i];
    }

    int* count = (int*)calloc(max + 1, sizeof(int));
    int* output = (int*)malloc(sizeof(int) * n);

    // count each number
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
        // count = [1, 1, 3, 2, 2, 0, 0, 0, 1]
    }

    // cumulative sum
    for (int i = 1; i <= max; i++) {
        count[i] += count[i-1];
        // count = [1, 2, 5, 7, 9, 9, 9, 9, 10]
    }

    // 안정 정렬을 위해서 뒤에서부터 정렬
    // sort from the rear of array for stable sorting
    for (int i = n-1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    free(count);
    free(output);
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1, 0, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before Sorting:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    countingSort(arr, n);

    printf("After Sorting:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
#include <stdio.h>

// void shellSort(int arr[], int n) {
//     int gap, j, k;
//     for(gap = n / 2; gap > 0; gap /= 2) {
//         for(j = gap; j < n; j++) {
//             for(k = j-gap; k >= 0; k -= gap) {
//                 if(arr[k+gap] >= arr[k]) {
//                     break;
//                 } else { // 뒷값이 더 작은 경우
//                     int temp = arr[k+gap];
//                     arr[k+gap] = arr[k];
//                     arr[k] = temp;
//                 }
//             }
//         }
//     }
// }

void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int key = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > key; j -= gap) { // 정렬된 부분 배열 안에 요소를 적절한 위치에 삽입하는 괴정
                arr[j] = arr[j - gap];
            }
            arr[j] = key;
        }
    }
}

int main() {
    int n;
    n = 10;
    int arr[10] = {33, 45, 62, 12, 98, 32, 54, 16, 56, 43};

    printf("Array before Sorting: ");
    for(int i = 0; i < n; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");

    shellSort(arr, n);

    printf("Array after Sorting: ");
    for(int i = 0; i < n; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");

    return 0;
}
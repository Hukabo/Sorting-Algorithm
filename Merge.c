#include <stdio.h>
#define max 10

int a[11] = {10, 35, 19, 26, 31, 27, 33, 14, 42, 44, 0}; // 원본 배열
int b[10]; // 보조 배열

void merging(int low, int mid, int high) {
    
    int l1, l2, i;
    for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {

        // l1과 l2의 값을 비교하여 작은 값을 보조 배열에 삽입
        if(a[l1] <= a[l2])
            b[i] = a[l1++];
        else
            b[i] = a[l2++];
    }

    // 한쪽이 모두 소진됐다면 남은 한쪽의 요소들을 보조 배열에 삽입
    while(l1 <= mid)
        b[i++] = a[l1++];
    while(l2 <= high)
        b[i++] = a[l2++];

    // 원본 배열에 정렬된 보조 배열을 복사
    for(i = low; i <= high; i++)
        a[i] = b[i];
}

void sort(int low, int high) {

    if(low < high) {
        int mid = (low + high) / 2;
        sort(low, mid); // 왼쪽 배열 나누기
        sort(mid+1, high); // 오른쪽 배열 나누기
        merging(low, mid, high);
    } else {
        return;
    }
}

int main() {
    int i;
    printf("Array before sorting:\n");
    for(i = 0; i <= max; i++)
        printf("%d ", a[i]);

    sort(0, max);

    printf("\nArray after sorting:\n");
    for(i = 0; i <= max; i++)
        printf("%d ", a[i]);

    return 0;
}
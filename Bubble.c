#include <stdio.h>

void bubbleSort(int array[], int size) {

    for(int i = 0; i < size; i++) {

        int swap = 0; // flag to detect if any swap occureed or not

        for(int j = 0; j < (size-1) - i; j++) {
            if(array[j] > array[j+1]) { // when the current item is bigger than next

                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;

                swap = 1; // set swap flag
            }
        }

        if(!swap)
            break;
    }
}

int main() {
    int n;
    n = 5;
    int arr[5] = {67, 44, 82, 17, 20};
    printf("Array before Sotring: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    bubbleSort(arr, n);
    printf("Array after Sorting: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
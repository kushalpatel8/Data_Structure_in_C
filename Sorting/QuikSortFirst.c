#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition (int arr[], int si, int ei) {
    int pe = arr[si];
    int pidx = si;

    for (int i = si + 1; i <= ei; i++) {
        if (arr[i] <= pe) {
            pidx++;
            swap (&arr[i], &arr[pidx]);
        }
    }
    swap (&arr[si], &arr[pidx]);
    return pidx;
}

void QuikSort(int arr[], int si, int ei) {
    if (si >= ei) return;

    int pi = partition(arr, si, ei);
    QuikSort(arr, si, pi - 1);
    QuikSort(arr, pi + 1, ei);
}

int main() {
    int arr[] = {5, 1, 8, 2, 7, 6, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    QuikSort(arr, 0, n - 1);

    printf("\nSorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
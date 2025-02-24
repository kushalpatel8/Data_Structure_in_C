#include <stdio.h>

void swap (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition (int arr[], int si, int ei) {
    int pe = arr[(si + ei) / 2];
    int count = 0;
    for (int i = si; i < ei; i++) {
        if (i == (si + ei) / 2) continue;
        if (arr[i] <= pe) count++;
    }

    int pidx = si + count;
    swap (&arr[(si + ei) / 2], &arr[pidx]);

    int i = si, j = ei;
    while (i < pidx && j > pidx) {
        if (arr[i] > pe && arr[j] <= pe) {
            swap (&arr[i], &arr[j]);
            i++;
            j--;
        } 
        if (arr[i] <= pe) {
            i++;
        }
        else if (arr[j] > pe) {
            j--;
        }
    }
    return pidx;
}

void QuikSort (int arr[], int si, int ei) {
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
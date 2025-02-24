#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int arr[] = {5, 1, 3, 0, 4, 9, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int tgt = 6;

    
    qsort(arr, n, sizeof(int), compare);

    printf("Array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

   
    int low = 0, high = n - 1;
    bool flag = false;

    while (low <= high) {
        int mid = low + (high - low) / 2; 

        if (arr[mid] == tgt) {
            flag = true;
            break;
        } else if (arr[mid] < tgt) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (flag) {
        printf("Element Found.");
    } else {
        printf("Element Not Found.");
    }
    return 0;
}

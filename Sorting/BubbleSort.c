#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main () {
    int arr[] = {5, 1, 3, 0, 4, 9, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    for (int i = 0; i < n; i++ ) {
        bool flag  = true;
        for (int j = 0; j < n -i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = false;
            }    
        }
        if (flag == true) {
            break;
        }
    }

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
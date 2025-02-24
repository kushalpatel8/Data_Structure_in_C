#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main () {
    int arr[] = {5, 1, 3, 0, 4, 9, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int tgt = 6;

    printf("Array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    bool flag = false;
    for (int i = 0; i < n; i++) {
        if (arr[i] == tgt) {
            flag = true;
            break;
        }
    }   

    if (flag == true) {
        printf ("Element  Found.");
    }
    else {
        printf("Element Not Found");
    }

    return 0;
}
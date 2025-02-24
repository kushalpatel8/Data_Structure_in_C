#include <stdio.h>
#include <stdlib.h>

void merge(int a[], int n1, int b[], int n2, int res[])
{
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            res[k++] = a[i++];
        }
        else
        {
            res[k++] = b[j++];
        }
    }

    while (i < n1)
    {
        res[k++] = a[i++];
    }

    while (j < n2)
    {
        res[k++] = b[j++];
    }
}

void mergesort(int arr[], int n)
{
    if (n == 1)
        return;

    int n1 = n / 2;
    int n2 = n - n1;

    int *a = (int *)malloc(n1 * sizeof(int));
    int *b = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
    {
        a[i] = arr[i];
    }
    for (int i = 0; i < n2; i++)
    {
        b[i] = arr[i + n1];
    }

    mergesort(a, n1);
    mergesort(b, n2);
    merge(a, n1, b, n2, arr);

    free(a);
    free(b);
}

int main()
{
    int arr[] = {5, 1, 3, 0, 4, 9, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    mergesort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

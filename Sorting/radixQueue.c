#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define QSZ 100

typedef struct Queue {
    int arr[QSZ];
    int front, rear;
} Queue;

void initialize(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

bool isempty(Queue *q) {
    return q->front == -1;
}

void enqueue(Queue *q, int val) {
    if (q->rear == QSZ - 1) {
        printf("Queue overflow\n");
        exit(1);
    }
    if (isempty(q)) {
        q->front = 0;
    }
    q->arr[++q->rear] = val;
}

int dequeue(Queue *q) {
    if (isempty(q)) {
        printf("Queue underflow\n");
        exit(1);
    }
    int val = q->arr[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1; 
    } else {
        q->front++;
    }
    return val;
}

int Max(int *arr, int n) {
    int maxval = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxval) {
            maxval = arr[i];
        }
    }
    return maxval;
}

void radixSort(int *arr, int n) {
    int maxval = Max(arr, n);
    int maxDigit = (int)(log10(maxval)) + 1; 

    Queue buckets[10];
    for (int i = 0; i < 10; i++) {
        initialize(&buckets[i]);
    }

    int placevalue = 1;
    for (int d = 0; d < maxDigit; d++) {
        for (int i = 0; i < n; i++) {
            int bidx = (arr[i] / placevalue) % 10;
            enqueue(&buckets[bidx], arr[i]);
        }

        int idx = 0;
        for (int i = 0; i < 10; i++) {
            while (!isempty(&buckets[i])) {
                arr[idx++] = dequeue(&buckets[i]);
            }
        }
        placevalue *= 10; 
    }
}


int main() {
    int arr[] = {5, 1, 3, 0, 4, 9, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    radixSort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}



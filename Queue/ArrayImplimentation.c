#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define CAPACITY 5  // Define the queue capacity as a macro

typedef struct Queue {
    int frnt;
    int bck;
    int arr[CAPACITY];  // Fixed-size array
} Queue;

void initialize(Queue* q) {
    q->frnt = 0;
    q->bck = 0;
}

void push(Queue* q, int val) {
    if (q->bck == CAPACITY) {
        printf("Queue is full\n");
        return;
    }
    q->arr[q->bck] = val;
    q->bck++;
}

void pop(Queue* q) {
    if (q->frnt == q->bck) {
        printf("Queue is empty.\n");
        return;
    }
    q->frnt++;
}

int front(Queue* q) {
    if (q->frnt == q->bck) {
        printf("Queue is empty.\n");
        return -1;
    }
    return q->arr[q->frnt];
}

int back(Queue* q) {  // Corrected the function name from 'bck' to 'back'
    if (q->frnt == q->bck) {
        printf("Queue is empty.\n");
        return -1;
    }
    return q->arr[q->bck - 1];
}

int size(Queue* q) {
    return q->bck - q->frnt;
}

bool empty(Queue* q) {
    return q->frnt == q->bck;
}

void display(Queue* q) {
    if (empty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = q->frnt; i < q->bck; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main() {
    Queue q;
    initialize(&q);  // Initialize the queue

    push(&q, 10);
    push(&q, 20);
    push(&q, 30);
    push(&q, 40);
    display(&q);

    // push(&q, 50);
    // push(&q, 60);  // This will trigger the "Queue is full" message
    // display(&q);

    pop(&q);
    printf("Queue element after pop\n");
    display(&q);

    printf("Is the queue empty? %d\n", empty(&q));
    printf("Front element: %d\n", front(&q));
    printf("Back element: %d\n", back(&q));
    printf("Queue size: %d\n", size(&q));

    return 0;
}

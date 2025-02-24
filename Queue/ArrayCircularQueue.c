#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_SIZE 100 // Define the maximum size of the queue

typedef struct Queue {
    int arr[MAX_SIZE];
    int front;
    int rear;
    int size;
} Queue;

void initialize(Queue* q) {
    q->front = -1;
    q->rear = -1;
    q->size = 0;
}

bool isEmpty(Queue* q) {
    return q->size == 0;
}

bool isFull(Queue* q) {
    return q->size == MAX_SIZE;
}

void push(Queue* q, int val) {
    if (isFull(q)) {
        printf("Queue is full. Cannot add %d.\n", val);
        return;
    }

    if (isEmpty(q)) {
        q->front = 0; // Initialize front to 0 when the first element is added
    }
    q->rear = (q->rear + 1) % MAX_SIZE; // Circular increment
    q->arr[q->rear] = val;
    q->size++;
}

void pop(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot pop.\n");
        return;
    }

    if (q->front == q->rear) {
        // Reset the queue when it becomes empty
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX_SIZE; // Circular increment
    }
    q->size--;
}

int front(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return -1;
    }
    return q->arr[q->front];
}

int back(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return -1;
    }
    return q->arr[q->rear];
}

int size(Queue* q) {
    return q->size;
}

void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    int i = q->front;
    int count = q->size;
    while (count--) {
        printf("%d ", q->arr[i]);
        i = (i + 1) % MAX_SIZE; // Circular increment
    }
    printf("\n");
}

int main() {
    Queue q;
    initialize(&q);

    push(&q, 10);
    push(&q, 20);
    push(&q, 30);
    push(&q, 40);
    display(&q);

    // push(&q, 50);
    // push(&q, 60);
    // display(&q);

    pop(&q);
    display(&q);

    printf("Front element: %d\n", front(&q));
    printf("Back element: %d\n", back(&q));
    printf("Is the queue empty? %d\n", isEmpty(&q));
    return 0;
}

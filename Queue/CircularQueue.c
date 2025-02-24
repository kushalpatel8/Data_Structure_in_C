#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* frnt;
    Node* bck;
    int size;
} Queue;

void intilize(Queue* q) {
    q->frnt = q->bck = NULL;
    q->size = 0;
}

Node* getNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

void push(Queue* q, int val) {
    Node* newNode = getNode(val);
    if (q->bck == NULL) {
        // If the queue is empty, initialize the front and back to the new node
        q->frnt = q->bck = newNode;
        newNode->next = newNode; // Point to itself to form a circular structure
    } else {
        newNode->next = q->frnt; // New node points to the front node
        q->bck->next = newNode;  // Current back node points to the new node
        q->bck = newNode;        // Update the back pointer to the new node
    }
    q->size++;
}

void pop(Queue* q) {
    if (q->frnt == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    if (q->frnt == q->bck) {
        // Only one element in the queue
        free(q->frnt);
        q->frnt = q->bck = NULL;
    } else {
        Node* temp = q->frnt;
        q->frnt = q->frnt->next;
        q->bck->next = q->frnt; // Update the back node's next to the new front
        free(temp);
    }
    q->size--;
}

int front(Queue* q) {
    if (q->frnt == NULL) {
        printf("Queue is empty.\n");
        return -1;
    }
    return q->frnt->val;
}

int back(Queue* q) {
    if (q->bck == NULL) {
        printf("Queue is empty.\n");
        return -1;
    }
    return q->bck->val;
}

int size(Queue* q) {
    return q->size;
}

bool empty(Queue* q) {
    return q->size == 0;
}

void display(Queue* q) {
    if (q->frnt == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    Node* temp = q->frnt;
    do {
        printf("%d ", temp->val);
        temp = temp->next;
    } while (temp != q->frnt); // Stop when we loop back to the front
    printf("\n");
}

int main() {
    Queue q;
    intilize(&q);

    push(&q, 10);
    push(&q, 20);
    push(&q, 30);
    push(&q, 40);
    display(&q);

    push(&q, 50);
    push(&q, 60);
    display(&q);

    pop(&q);
    display(&q);

    printf("Is the queue empty? %d\n", empty(&q));
    return 0;
}

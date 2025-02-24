#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int val;
    struct Node* next;
}Node;

typedef struct Queue {
    Node* frnt;
    Node* bck;
    int size;
}Queue;

void intilize (Queue* q) {
    q->frnt = q->bck = NULL;
    q->size = 0;
}

Node* getNode (int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

void push (Queue* q, int val) {
    Node*newNode = getNode(val);
    if (q->bck == NULL) {
        q->frnt = q->bck = newNode;
    }
    else {
        q->bck->next = newNode;
        q->bck = newNode;
    }
    q->size++;
}

void pop (Queue* q) {
    if (q->frnt == NULL) {
        printf ("Queue is empty.\n");
        return;
    }
    Node* temp = q->frnt;
    q->frnt = q->frnt->next;
    if (q->frnt == NULL) {
        q->bck = NULL;
    }
    free(temp);
    q->size--;
}

int front (Queue* q) {
    if (q->frnt == NULL) {
        printf("Queue is empty.\n");
        return -1;
    }
    return q->frnt->val;
}

int back (Queue* q) {
    if (q->bck == NULL) {
        printf("Queue is empty.\n");
        return -1;
    }
    return q->bck->val;
}

int size (Queue* q) {
    return q->size;
}

bool empty(Queue* q) {
    return q->size == 0;
}

void display(Queue* q) {
    printf("\n");
    Node* temp = q->frnt;
    while (temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

int main () {
    Queue q;
    intilize(&q);

    // push(&q, 10);
    // push(&q, 20);
    push(&q, 30);
    push(&q, 40);
    // display(&q);

    push(&q, 50); 
    push(&q, 60);  
    display(&q);
   printf("%d",front(&q));

    pop(&q);
    display(&q);

    // printf("Is the queue empty? %d\n", empty(&q)); 
    return 0;
}
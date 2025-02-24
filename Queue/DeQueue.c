#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int val;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct Deque {
    Node* start;
    Node* end;
    int size;
} Deque;

Node* getNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void initialize(Deque* dq) {
    dq->start = dq->end = NULL;
    dq->size = 0;
}

void push_back(Deque* dq, int val) {
    Node* newNode = getNode(val);
    if (dq->start == NULL) {
        dq->start = dq->end = newNode;
    } else {
        dq->end->next = newNode;
        newNode->prev = dq->end;
        dq->end = newNode;
    }
    dq->size++;
}

void push_front(Deque* dq, int val) {
    Node* newNode = getNode(val);
    if (dq->start == NULL) {
        dq->start = dq->end = newNode;
    } else {
        newNode->next = dq->start;
        dq->start->prev = newNode;
        dq->start = newNode;
    }
    dq->size++;
}

void pop_front(Deque* dq) {
    if (dq->size == 0) {
        printf("Deque is empty.\n");
        return;
    }
    Node* temp = dq->start;
    dq->start = dq->start->next;
    if (dq->start != NULL) {
        dq->start->prev = NULL;
    } else {
        dq->end = NULL;
    }
    free(temp);
    dq->size--;
}

void pop_back(Deque* dq) {
    if (dq->size == 0) {
        printf("Deque is empty.\n");
        return;
    }
    Node* temp = dq->end;
    dq->end = dq->end->prev;
    if (dq->end != NULL) {
        dq->end->next = NULL;
    } else {
        dq->start = NULL;
    }
    free(temp);
    dq->size--;
}

int front(Deque* dq) {
    if (dq->size == 0) {
        printf("Deque is empty.\n");
        return -1;
    }
    return dq->start->val;
}

int back(Deque* dq) {
    if (dq->size == 0) {
        printf("Deque is empty.\n");
        return -1;
    }
    return dq->end->val;
}

void display(Deque* dq) {
    Node* temp = dq->start;
    while (temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

int size(Deque* dq) {
    return dq->size;
}

bool isEmpty(Deque* dq) {
    return dq->size == 0;
}

int main() {
    Deque dq;
    initialize(&dq);

    push_back(&dq, 10);
    push_back(&dq, 20);
    push_back(&dq, 30);
    push_back(&dq, 40);
    display(&dq); 

    push_front(&dq, 50);
    push_front(&dq, 60);
    push_front(&dq, 70);
    display(&dq); 
    pop_back(&dq);
    display(&dq);

    pop_front(&dq);
    display(&dq); 

    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node {
    int val;
    struct Node*next;
}Node;

typedef struct stack {
    Node* start;
    int size;
}stack;

Node *getNode (int val) {
    Node*newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

void initialize(stack* st) {
    st->start = NULL;
    st->size = 0;
}

void push (stack* st, int val) {
    Node* newNode = getNode(val);
    newNode->next = st->start;
    st->start = newNode;
    st->size++;
}

void pop (stack* st) {
    if (st->start == NULL) {
        printf("Stack is Empty.\n");
    }
    Node* p = st->start;
    st->start = st->start->next;
    free(p);
    st->size--;
}

int top (stack* st) {
    if(st->start == NULL) {
        printf("Stack is Empty.\n");
        return -1;
    }
    return st->start->val;
}

int size(stack* st) {
    return st->size;
}

bool isEmpty(stack* st) {
    return st->start == NULL;
}

void print(stack* st) {
    if (isEmpty(st)) {
        printf("Stack is Empty.\n");
        return;
    }

    printf("Stack elements: ");
    Node* temp = st->start;
    while (temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    stack st;
    initialize(&st);  // Initialize the stack

    // push(&st, 10);
    // push(&st, 20);
    push(&st, 30);
    push(&st, 40);
    push(&st, 50);

    print(&st);
    
    printf("Top element: %d\n", top(&st));
    printf("Stack size: %d\n", size(&st));

    pop(&st);
    printf("Top element after pop: %d\n", top(&st));
    printf("Stack size after pop: %d\n", size(&st));

    return 0;
}

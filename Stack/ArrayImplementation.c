#include <stdio.h>
#include <stdbool.h>
 
#define Max 5
typedef struct stack {
    int arr[Max];  
    int idx;       
} stack;

void initialize(stack *st) {
    st->idx = -1;
}

void push(stack *st, int val) {
    if (st->idx == Max - 1) {
        printf("Stack is full.\n");
        return;  
    }
    st->arr[++(st->idx)] = val;
}

void pop(stack *st) {
    if (st->idx == -1) {
        printf("Stack is empty.\n");
        return;  
    }
    st->idx--;
}

int top(stack *st) {
    if (st->idx == -1) {
        printf("Stack is empty.\n");
        return -1; 
    }
    return st->arr[st->idx];
}

int size(stack *st) {
    return st->idx + 1;
}

bool isEmpty(stack *st) {
    return st->idx == -1;
}

void display(stack *st) {
    if (isEmpty(st)) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack elements: ");
    for (int i = st->idx; i >= 0; i--) {
        printf("%d ", st->arr[i]);
    }
    printf("\n");
}

int main() {
    stack st;
    initialize(&st); 
    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    display(&st);
    // push(&st, 40);
    // push(&st, 50);
    // push(&st, 60);  
    printf("Top element: %d\n", top(&st));
    printf("Stack size: %d\n", size(&st));

    pop(&st);
    printf("Top element after pop: %d\n", top(&st));
    printf("Stack size after pop: %d\n", size(&st));

    return 0;
}

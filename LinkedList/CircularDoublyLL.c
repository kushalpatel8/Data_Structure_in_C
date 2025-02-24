#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node*next;
    struct Node*prev;
}Node;

typedef struct CDLL {
    Node*start;
    int size;
}CDLL;

Node* getNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next =NULL;
    newNode->prev = NULL;
    return newNode;
}

void intialize(CDLL* ll) {
    ll->start = NULL;
    ll->size = 0;
}

void insertAtbegin(CDLL* ll, int data) {
    Node*newNode = getNode(data);
    if(ll->size == 0) {
        ll->start = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    }
    else {
        Node* end =ll->start->prev;
        newNode->next = ll->start;
        newNode->prev = end;
        end->next = newNode;
        ll->start->prev = newNode;
        ll->start = newNode;
    }
    ll->size++;
}

void insertAtend(CDLL*ll, int data) {
    Node*newNode = getNode(data);
    if(ll->size == 0) {
        ll->start = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    }
    else {
        Node* end  = ll->start->prev;
        end->next = newNode;
        newNode->prev = end;
        newNode->next = ll->start;
        ll->start->prev = newNode;
    }
    ll->size++;
}

void insertAtindex(CDLL* ll, int idx, int data) {
    Node* newNode = getNode(data);
    if (idx > ll->size || idx < 0) {
        printf("Invalid Input\n");
    }
    else if(idx == 0) {
        insertAtbegin(ll, data);
    }
    else if(idx == ll->size){
        insertAtend(ll, data);
    }
    else {
        Node* temp = ll->start;
        for(int i = 1; i < idx; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp;
        ll->size++;
    }
}

void display(CDLL* ll) {
    if (ll->size == 0) {
        printf("List is empty.\n");
        return;
    }
    Node* temp = ll->start;
    for (int i = 0; i < ll->size; i++) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    CDLL ll;
    intialize(&ll);
    insertAtend(&ll, 10);
    insertAtend(&ll, 20);
    insertAtend(&ll, 30);
    insertAtend(&ll, 40);
    insertAtend(&ll, 50);
    insertAtbegin(&ll, 60);
    display(&ll);
}


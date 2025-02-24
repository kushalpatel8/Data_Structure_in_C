#include<stdlib.h>
#include<stdio.h>
 
typedef struct Node {
    int val;
    struct Node*next;
}Node;

typedef struct Linklist {
    Node*start;
    Node*end;
    int size;
}Linklist;

Node* getNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;
}

void intializell(Linklist* ll) {
    ll->start = ll->end =NULL;
    int size = 0;
}

void insertAtBegining(int val, Linklist* ll) {
    Node* newNode = getNode(val);
    if(ll->size == 0) {
        ll->start = ll->end =newNode;
    }
    else {
        newNode->next = ll->start;
        ll->start = newNode;
    }
    ll->size++;
}

void insertAtEnd(int val, Linklist* ll) {
    Node* newNode = getNode(val);
    if(ll->size == 0) {
        ll->start = ll->end =newNode;
    }
    else {
        Node* temp = ll->start;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    ll->size;
}
void insertAtIdx(int val, Linklist* ll,int idx) {
    Node* newNode =getNode(val);
    if(idx == 0) {
        insertAtBegining(val, ll);
    }
    if(idx == ll->size - 1) {
        insertAtEnd(val, ll);
    }
    else {
        Node*temp = ll->start;
        for(int i = 1; i <= idx; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        ll->size;
    }
}
void display(Linklist* ll) {
    Node* temp = ll->start;
    while(temp->next != NULL) {
        printf("%d ",temp->val);
        temp = temp->next;
    }
    printf("\n");
}

 int main(){
    Linklist ll;
    intializell(&ll);
    insertAtEnd(10, &ll);
    display(&ll);

    insertAtEnd(20, &ll);
    display(&ll);

    insertAtEnd(30, &ll);
    display(&ll);

    insertAtEnd(40, &ll);
    display(&ll);

    insertAtBegining(50, &ll);
    display(&ll);

    insertAtBegining(29, &ll);
    display(&ll);

    insertAtIdx( 80, &ll, 4);
    display(&ll);
 }
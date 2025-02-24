#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

typedef struct CircularLinkedList {
    Node* head;
    int size;
} CircularLinkedList;

Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

void initList(CircularLinkedList* list) {
    list->head = NULL;
    list->size = 0;
}


void insertAthead(CircularLinkedList* list, int val) {
    Node* newNode = createNode(val); 
    if (list->size == 0) {
        newNode->next = newNode; 
        list->head = newNode;
    } else {
        Node* temp = list->head;
        while (temp->next != list->head) {
            temp = temp->next;  
        }
        newNode->next = list->head;
        temp->next = newNode;  
        list->head = newNode; 
    }
    
    list->size++;
}

void insertAttail(CircularLinkedList* list, int val) {
    Node* newNode = createNode(val);
    
    if (list->size == 0) {
        newNode->next = newNode; 
        list->head = newNode;
    } else {
        Node* temp = list->head;
        while (temp->next != list->head) {
            temp = temp->next;  
        }
        temp->next = newNode;
        newNode->next = list->head;  
    }
    list->size++;
}


void insertAtidx(CircularLinkedList* list, int idx, int val) {
    if (idx < 0 || idx > list->size) {
        printf("Invalid index\n");
        return;
    }

    if (idx == 0) {
        insertAthead(list, val);
    } else {
        Node* newNode = createNode(val);
        Node* temp = list->head;
        for (int i = 1; i < idx; i++) {
            temp = temp->next; 
        }
        newNode->next = temp->next;
        temp->next = newNode;
        list->size++;
    }
}

void deleteAthead(CircularLinkedList* list) {
    if (list->size == 0) {
        printf("List is empty.\n");
        return;
    }
    Node* temp = list->head;
    if (list->size == 1) {
        free(list->head);
        list->head = NULL;
    } else {
        Node* last = list->head;
        while (last->next != list->head) {
            last = last->next;  
        }
        last->next = list->head->next;
        list->head = list->head->next;
        free(temp);
    }
    list->size--;
}

void deleteAttail(CircularLinkedList* list) {
    if (list->size == 0) {
        printf("List is empty.\n");
        return;
    }
    if (list->size == 1) {
        free(list->head);
        list->head = NULL;
    } else {
        Node* temp = list->head;
        Node* prev = NULL;
        while (temp->next != list->head) {
            prev = temp;
            temp = temp->next;  
        }
        prev->next = list->head;
        free(temp);
    }
    list->size--;
}

void deleteAtidx(CircularLinkedList* list, int idx) {
    if (idx < 0 || idx >= list->size) {
        printf("Invalid index\n");
        return;
    }
    if (idx == 0) {
        deleteAthead(list);
    } else {
        Node* temp = list->head;
        Node* prev = NULL;

        for (int i = 0; i < idx; i++) {
            prev = temp;
            temp = temp->next;
        }

        prev->next = temp->next;
        free(temp);

        list->size--;
    }
}

void display(CircularLinkedList* list) {
    if (list->size == 0) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = list->head;
    do {
        printf("%d ", temp->val);
        temp = temp->next;
    } while (temp != list->head);
    printf("\n");
}

int main() {
    CircularLinkedList list;
    initList(&list);

    insertAttail(&list, 10);
    display(&list);

    insertAttail(&list, 20);
    display(&list);

    insertAttail(&list, 30);
    display(&list);

    insertAttail(&list, 40);
    display(&list);

    insertAthead(&list, 50);
    display(&list);

    insertAthead(&list, 24);
    display(&list);

    insertAtidx(&list, 4, 80);
    display(&list);

    deleteAthead(&list);
    display(&list);

    deleteAttail(&list);
    display(&list);

    deleteAtidx(&list, 2);
    display(&list);

    return 0;
}


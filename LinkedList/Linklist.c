#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
};

struct SLL {
    struct Node* head;
    int size;
};

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

void initList(struct SLL* list) {
    list->head = NULL;
    list->size = 0;
}

void insertAthead(struct SLL* list, int val) {
    struct Node* temp = createNode(val);
    temp->next = list->head;
    list->head = temp;
    list->size++;
}

void insertAttail(struct SLL* list, int val) {
    struct Node* temp = createNode(val);
    if (list->size == 0) {
        list->head = temp;
    } else {
        struct Node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = temp;
    }
    list->size++;
}

void insertAtidx(struct SLL* list, int idx, int val) {
    if (idx > list->size || idx < 0) {
        printf("Invalid Input\n");
    } else if (idx == 0) {
        insertAthead(list, val);
    } else {
        struct Node* temp = createNode(val);
        struct Node* current = list->head;
        for (int i = 1; i < idx; i++) {
            current = current->next;
        }
        temp->next = current->next;
        current->next = temp;
        list->size++;
    }
}

void deleteAthead(struct SLL* list) {
    if (list->size == 0) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = list->head;
    list->head = list->head->next;
    free(temp);
    list->size--;
}

void deleteAttail(struct SLL* list) {
    if (list->size == 0) {
        printf("List is empty.\n");
        return;
    }
    if (list->size == 1) {
        deleteAthead(list);
        return;
    }
    struct Node* current = list->head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
    list->size--;
}

void deleteAtidx(struct SLL* list, int id) {
    int idx = id-1;
    if (idx < 0 || idx >= list->size) {
        printf("Invalid input.\n");
        return;
    } else if (idx == 0) {
        deleteAthead(list);
    } else {
        struct Node* current = list->head;
        for (int i = 1; i < idx ; i++) {
            current = current->next;
        }
        struct Node* toDelete = current->next;
        current->next = current->next->next;
        free(toDelete);
        list->size--;
    }
}

int getidx(struct SLL* list, int idx) {
    if (idx < 0 || idx >= list->size) {
        printf("Invalid input\n");
        return -1;
    }
    struct Node* temp = list->head;
    for (int i = 0; i < idx; i++) {
        temp = temp->next;
    }
    return temp->val;
}

void display(struct SLL* list) {
    struct Node* temp = list->head;
    while (temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

void alternatedisplay(struct SLL* ll) {
    struct Node* temp = ll->head;
    bool flag = true;
    while (temp != NULL) {
        if (flag == true) {
           printf("%d ", temp->val);
        }
        flag = !flag;
        temp = temp->next; 
    }
    printf("\n");
}

int main() {
    struct SLL list;
    initList(&list);
    insertAttail(&list, 5);
    insertAttail(&list, 10);
    insertAttail(&list, 20);
    insertAttail(&list, 40);
    insertAttail(&list, 50);
    insertAttail(&list, 60);
    display(&list);

    alternatedisplay(&list);

    return 0;
}

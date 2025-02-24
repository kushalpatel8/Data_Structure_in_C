#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int val;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct DLL
{
    Node *head;
    int size;
} DLL;

Node *createNode(int val)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void initList(DLL *list)
{
    list->head = NULL;
    list->size = 0;
}

void insertAthead(DLL *list, int val)
{
    Node *temp = createNode(val);
    if (list->size == 0)
    {
        list->head = temp;
    }
    else
    {
        temp->next = list->head;
        list->head->prev = temp;
        list->head = temp;
    }
    list->size++;
}

void insertAttail(DLL *list, int val)
{
    Node *temp = createNode(val);
    if (list->size == 0)
    {
        list->head = temp;
    }
    else
    {
        Node *current = list->head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = temp;
        temp->prev = current;
    }
    list->size++;
}

void insertAtidx(DLL *list, int idx, int val)
{
    if (idx > list->size || idx < 0)
    {
        printf("Invalid Input\n");
    }
    else if (idx == 0)
    {
        insertAthead(list, val);
    }
    else if (idx == list->size)
    {
        insertAttail(list, val);
    }
    else
    {
        Node *newNode = createNode(val);
        Node *temp = list->head;
        for (int i = 1; i < idx; i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next->prev = newNode;
        list->size++;
    }
}

void deleteAthead(DLL *list)
{
    if (list->size == 0)
    {
        printf("List is empty.\n");
        return;
    }
    Node *temp = list->head;
    list->head = list->head->next;
    if (list->head != NULL)
    {
        list->head->prev = NULL;
    }
    free(temp);
    list->size--;
}

void deleteAttail(DLL *list)
{
    if (list->size == 0)
    {
        printf("List is empty.\n");
        return;
    }
    if (list->size == 1)
    {
        deleteAthead(list);
        return;
    }
    Node *temp = list->head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    Node *toDelete = temp->next;
    temp->next = NULL;
    free(toDelete);
    list->size--;
}

void deleteAtidx(DLL *list, int idx)
{
    if (idx < 0 || idx >= list->size)
    {
        printf("Invalid input.\n");
        return;
    }
    else if (idx == 0)
    {
        deleteAthead(list);
    }
    else if (idx == list->size - 1)
    {
        deleteAttail(list);
    }
    else
    {
        Node *temp = list->head;
        for (int i = 1; i < idx; i++)
        {
            temp = temp->next;
        }
        Node *toDelete = temp->next;
        temp->next = temp->next->next;
        temp->next->prev = temp;
        free(toDelete);
        list->size--;
    }
}

int getidx(DLL *list, int idx)
{
    if (idx < 0 || idx >= list->size)
    {
        printf("Invalid input\n");
        return -1;
    }
    Node *temp = list->head;
    for (int i = 0; i < idx; i++)
    {
        temp = temp->next;
    }
    return temp->val;
}

void display(DLL *list)
{
    Node *temp = list->head;
    while (temp != NULL)
    {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    DLL list;
    initList(&list);

    insertAttail(&list, 10);
    insertAttail(&list, 20);
    insertAttail(&list, 30);
    // insertAttail(&list, 40);
    // insertAttail(&list, 50);
    // insertAttail(&list, 60);
    display(&list);

    // insertAttail(&list, 70);
    // display(&list);

    insertAthead(&list, 80);
    display(&list);

    insertAtidx(&list, 2, 90);
    display(&list);

    deleteAthead(&list);
    display(&list);

    deleteAttail(&list);
    display(&list);

    printf("Name - Kushal Patel\n");
    printf("Roll No - 2301430130047");

    // deleteAtidx(&list, 2);
    // display(&list);

    // printf("%d\n", getidx(&list, 4));

    // display(&list);

    return 0;
}

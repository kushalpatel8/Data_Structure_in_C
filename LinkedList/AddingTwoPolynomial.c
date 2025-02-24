#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int coeff;
    int exp;
    struct Node *next;
} Node;

typedef struct Polynomial
{
    Node *start;
    int size;
} Polynomial;

Node *getNode(int coeff, int exp)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

void intializePolynomial(Polynomial *pl)
{
    pl->start = NULL;
    pl->size = 0;
}

void insertTerm(Polynomial *pl, int coeff, int exp)
{
    Node *newNode = getNode(coeff, exp);
    newNode->next = pl->start;
    pl->start = newNode;
    pl->size++;
}

void display(Polynomial *pl)
{
    Node *temp = pl->start;
    while (temp != NULL)
    {
        if (temp->coeff != 0)
        {
            printf("%dx^%d", temp->coeff, temp->exp);
            if (temp->next != NULL)
            {
                printf(" + ");
            }
        }
        temp = temp->next;
    }
    printf("\n");
}

Polynomial addPolynomial(Polynomial *pl1, Polynomial *pl2)
{
    Polynomial res;
    intializePolynomial(&res);
    Node *p1 = pl1->start;
    Node *p2 = pl2->start;

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->exp > p2->exp)
        {
            insertTerm(&res, p1->coeff, p1->exp);
            p1 = p1->next;
        }
        else if (p1->exp < p2->exp)
        {
            insertTerm(&res, p2->coeff, p2->exp);
            p2 = p2->next;
        }
        else
        {
            int newcoeff = p1->coeff + p2->coeff;
            insertTerm(&res, newcoeff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    while (p1 != NULL)
    {
        insertTerm(&res, p1->coeff, p1->exp);
        p1 = p1->next;
    }

    while (p2 != NULL)
    {
        insertTerm(&res, p2->coeff, p2->exp);
        p2 = p2->next;
    }
    return res;
}

// void freePolynomial(Polynomial* pl) {
//     Node* current = pl->start;
//     Node* next;
//     while (current != NULL) {
//         next = current->next;
//         free(current);
//         current = next;
//     }
//     pl->start = NULL;
//     pl->size = 0;
// }

int main()
{
    Polynomial pl1, pl2;
    intializePolynomial(&pl1);
    intializePolynomial(&pl2);

    insertTerm(&pl1, 3, 0);
    insertTerm(&pl1, 5, 1);
    insertTerm(&pl1, 3, 2);

    insertTerm(&pl2, 8, 0);
    insertTerm(&pl2, 6, 1);

    printf("First Polynomial: ");
    display(&pl1);
    printf("Second Polynomial: ");
    display(&pl2);

    Polynomial result = addPolynomial(&pl1, &pl2);
    printf("Resultant Polynomial: ");
    display(&result);

    // freePolynomial(&pl1);
    // freePolynomial(&pl2);
    // freePolynomial(&result);

    return 0;
}

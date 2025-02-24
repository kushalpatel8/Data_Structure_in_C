#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void Pre_Order_Traversal(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->val);
    Pre_Order_Traversal(root->left);
    Pre_Order_Traversal(root->right);
}

void In_Order_Traversal(Node* root) {
    if (root == NULL) return;
    In_Order_Traversal(root->left);
    printf("%d ", root->val);
    In_Order_Traversal(root->right);
}

void Post_Order_Traversal(Node* root) {
    if (root == NULL) return;
    Post_Order_Traversal(root->left);
    Post_Order_Traversal(root->right);
    printf("%d ", root->val);
}

int main() {

    Node* a = createNode(1);
    Node* b = createNode(2);
    Node* c = createNode(3);
    Node* d = createNode(4);
    Node* e = createNode(5);
    Node* f = createNode(6);
    Node* g = createNode(7);

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;

    printf("Pre-order Traversal:\n");
    Pre_Order_Traversal(a);
    printf("\n");

    printf("In-order Traversal:\n");
    In_Order_Traversal(a);
    printf("\n");

    printf("Post-order Traversal:\n");
    Post_Order_Traversal(a);
    // printf("\n");

    return 0;
}

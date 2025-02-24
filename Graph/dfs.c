#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Stack {
    int items[MAX];
    int top;
};

struct Graph {
    int vertices;
    int adjMat[MAX][MAX];
    int visited[MAX];
};

struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    return stack;
}

void push(struct Stack* stack, int value) {
    if (stack->top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack->items[++stack->top] = value;
}

int pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack->items[stack->top--];
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

struct Graph* createGraph(int vertices) {
    struct Graph* G = (struct Graph*)malloc(sizeof(struct Graph));
    G->vertices = vertices;
    for (int i = 0; i < vertices; i++) {
        G->visited[i] = 0;
        for (int j = 0; j < vertices; j++) {
            G->adjMat[i][j] = 0;
        }
    }
    return G;
}

void addEdge(struct Graph* G, int src, int dest) {
    G->adjMat[src][dest] = 1;
    G->adjMat[dest][src] = 1; // For undirected graph
}

void dfs(struct Graph* G, int startVertex) {
    struct Stack* stack = createStack();

    push(stack, startVertex);
    G->visited[startVertex] = 1;

    while (!isEmpty(stack)) {
        int currentVertex = pop(stack);
        printf(" %d\n", currentVertex);

        for (int i = G->vertices - 1; i >= 0; i--) { // Traverse in reverse for consistent order
            if (G->adjMat[currentVertex][i] == 1 && G->visited[i] == 0) {
                push(stack, i);
                G->visited[i] = 1;
            }
        }
    }

    free(stack);
}

int main() {
    int vertices = 6;

    struct Graph* graph = createGraph(vertices);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 4, 5);

    printf("DFS traversal starting from vertex 0:\n");
    dfs(graph, 0);

    return 0;
}
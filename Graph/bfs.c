#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

struct Queue
{
    int Nodes[MAX];
    int front, rear;
};

struct Graph
{
    int vertices;
    int adjMat[MAX][MAX];
    int visited[MAX];
};

struct Queue *createQueue()
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

void enqueue(struct Queue *q, int val)
{
    if (q->rear == MAX - 1)
    {
        printf("\nQueue is full");
        return;
    }
    else
    {
        if (q->front == -1)
        {
            q->front = 0;
        }
        q->rear++;
        q->Nodes[q->rear] = val;
    }
}

int dequeue(struct Queue *q)
{
    int val;
    if (q->front == -1)
    {
        printf("\nQueue is empty");
        return -1;
    }
    else
    {
        val = q->Nodes[q->front];
        q->front++;
        if (q->front > q->rear)
        {
            q->front = q->rear = -1;
        }
        return val;
    }
}

int isEmpty(struct Queue *q)
{
    return q->front == -1;
}

struct Graph *createGraph(int vertices)
{
    struct Graph *G = (struct Graph *)malloc(sizeof(struct Graph));
    G->vertices = vertices;
    for (int i = 0; i < vertices; i++)
    {
        G->visited[i] = 0;
        for (int j = 0; j < vertices; j++)
        {
            G->adjMat[i][j] = 0;
        }
    }
    return G;
}

void addEdge(struct Graph *G, int src, int dest)
{
    G->adjMat[src][dest] = 1;
    G->adjMat[dest][src] = 1;
}

void bfs(struct Graph *G, int start)
{
    struct Queue *q = createQueue();
    G->visited[start] = 1;
    enqueue(q, start);

    while (!isEmpty(q))
    {
        int currentVertex = dequeue(q);
        printf(" %d\n", currentVertex);

        for (int i = 0; i < G->vertices; i++)
        {
            if (G->adjMat[currentVertex][i] == 1 && G->visited[i] == 0)
            {
                G->visited[i] = 1;
                enqueue(q, i);
            }
        }
    }
}

int main()
{
    int vertices = 6;

    struct Graph *graph = createGraph(vertices);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 4, 5);

    printf("BFS traversal starting from vertex 0:\n");
    bfs(graph, 0);

        return 0;
}
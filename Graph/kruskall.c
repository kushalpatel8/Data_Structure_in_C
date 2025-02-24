#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int src, dest, wt;
} Edge;

int find(int parent[], int a) {
    if (parent[a] == a) return a;
    return parent[a] = find(parent, parent[a]);
}

void Union(int parent[], int rank[], int a, int b) {
    a = find(parent, a);
    b = find(parent, b);
    
    if (rank[a] >= rank[b]) {
        parent[b] = a;
        if (rank[a] == rank[b]) {
            rank[a]++;
        }
    } else {
        parent[a] = b;
    }
}

int cmp(const void *a, const void *b) {
    return ((Edge*)a)->wt - ((Edge*)b)->wt;
}

long long kruskals(Edge input[], int n, int e) {
    qsort(input, e, sizeof(Edge), cmp);
    
    int parent[n + 1], rank[n + 1];
    for (int i = 0; i <= n; i++) {
        parent[i] = i;
        rank[i] = 1;
    }
    
    int edgeCount = 0, i = 0;
    long long ans = 0;
    
    while (edgeCount < n - 1 && i < e) {
        Edge curr = input[i];
        int srcPar = find(parent, curr.src);
        int destPar = find(parent, curr.dest);
        
        if (srcPar != destPar) {
            Union(parent, rank, srcPar, destPar);
            ans += curr.wt;
            edgeCount++;
        }
        i++;
    }
    
    return (edgeCount == n - 1) ? ans : -1;
}

int main() {
    int n, e;
    scanf("%d %d", &n, &e);
    
    Edge *v = (Edge*)malloc(e * sizeof(Edge));
    for (int i = 0; i < e; i++) {
        scanf("%d %d %d", &v[i].src, &v[i].dest, &v[i].wt);
    }
    
    long long result = kruskals(v, n, e);
    
    if (result == -1) {
        printf("Graph is not connected, MST cannot be formed.\n");
    } else {
        printf("%lld\n", result);
    }
    
    free(v);
    return 0;
}

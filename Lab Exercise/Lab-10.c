#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int u, v, weight;
} Edge;

Edge edges[MAX];
int parent[MAX];
int rank[MAX];
int edgeCount = 0;

int compare(const void *a, const void *b) {
    return ((Edge *)a)->weight - ((Edge *)b)->weight;
}

int find(int i) {
    if (parent[i] == -1)
        return i;
    return find(parent[i]);
}

void unionSets(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);
    
    if (rootU != rootV) {
        if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}

void kruskal(int n) {
    qsort(edges, edgeCount, sizeof(edges[0]), compare);
    
    for (int i = 0; i < n; i++) {
        parent[i] = -1;
        rank[i] = 0;
    }

    printf("Edges in Minimum Spanning Tree:\n");
    int totalCost = 0;

    for (int i = 0; i < edgeCount; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        if (find(u) != find(v)) {
            unionSets(u, v);
            printf("%d -- %d == %d\n", u, v, edges[i].weight);
            totalCost += edges[i].weight;
        }
    }
    
    printf("Total cost of construction: %d\n", totalCost);
}

int main() {
    int n, e;
    
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter number of edges: ");
    scanf("%d", &e);
    
    printf("Enter edges (u v weight):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
        edgeCount++;
    }

    kruskal(n);

    return 0;
}



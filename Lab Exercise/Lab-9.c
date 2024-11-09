
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX

int graph[MAX][MAX], dist[MAX], visited[MAX];
int n;

void dijkstra(int start) {
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[start] = 0;

    for (int count = 0; count < n - 1; count++) {
        int minIndex = -1;
        int minValue = INF;

        
        for (int v = 0; v < n; v++) {
            if (!visited[v] && dist[v] < minValue) {
                minValue = dist[v];
                minIndex = v;
            }
        }

        visited[minIndex] = 1;

       
        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[minIndex][v] && dist[minIndex] != INF &&
                dist[minIndex] + graph[minIndex][v] < dist[v]) {
                dist[v] = dist[minIndex] + graph[minIndex][v];
            }
        }
    }
}

void printShortestPath(int start) {
    printf("Vertex\tDistance from Source %d\n", start);
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (use 0 for no edge):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    int start;
    printf("Enter starting vertex: ");
    scanf("%d", &start);

    dijkstra(start);
    printShortestPath(start);

    return 0;
}




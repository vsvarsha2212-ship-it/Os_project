#include <stdio.h>
#include <limits.h>

#define MAX 10   // maximum number of stations

int minDistance(int dist[], int visited[], int n) {
    int min = INT_MAX, index = -1;

    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            index = i;
        }
    }
    return index;
}

void dijkstra(int graph[MAX][MAX], int n, int src) {
    int dist[MAX];
    int visited[MAX];

    // Initialize distances and visited array
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0;

    // Find shortest path for all stations
    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, visited, n);
        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print result
    printf("\nShortest distance from Source Station %d:\n", src);
    for (int i = 0; i < n; i++) {
        printf("To Station %d : %d units\n", i, dist[i]);
    }
}

int main() {
    int n, src;
    int graph[MAX][MAX];

    printf("Enter number of metro stations: ");
    scanf("%d", &n);

    printf("\nEnter adjacency matrix (distance between stations):\n");
    printf("(Enter 0 if no direct route)\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("\nEnter source station number: ");
    scanf("%d", &src);

    dijkstra(graph, n, src);

    return 0;
}
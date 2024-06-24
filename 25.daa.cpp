#include <stdio.h>
#include <limits.h>

#define V 4
#define INF INT_MAX

int tsp(int graph[V][V], int path[], int n, int start, int visited) {
    if (visited == ((1 << n) - 1))
        return graph[start][0];

    int ans = INF;
    for (int i = 0; i < n; i++) {
        if ((visited & (1 << i)) == 0) {
            int new_ans = graph[start][i] + tsp(graph, path, n, i, visited | (1 << i));
            if (new_ans < ans) {
                ans = new_ans;
                path[visited] = i;
            }
        }
    }
    return ans;
}

int main() {
    int graph[V][V] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };
    int path[1 << V];
    int cost = tsp(graph, path, V, 0, 1);
    printf("Minimum cost: %d\n", cost);
    printf("Path: 0 ");
    int mask = 1;
    for (int i = 1; i < V; i++) {
        printf("%d ", path[mask]);
        mask |= (1 << path[mask]);
    }
    printf("0\n");
    return 0;
}


#include <stdio.h>
#include <limits.h>

#define INF INT_MAX

void printRoutingTable(int distance[][3], int nextHop[][3], int n) {
    char router = 'A';
    for (int i = 0; i < n; ++i) {
        printf("Final routing table of router %c:\n", router + i);
        printf("Destination  Distance  Next_hop\n");
        for (int j = 0; j < n; ++j) {
            printf("%c             ", router + j);
            if (distance[i][j] == INF)
                printf("∞         ");
            else
                printf("%d         ", distance[i][j]);
            if (nextHop[i][j] == -1)
                printf("None\n");
            else
                printf("%c\n", router + nextHop[i][j]);
        }
    }
}

void distanceVectorRouting(int graph[][3], int n) {
    int distance[3][3];
    int nextHop[3][3];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            distance[i][j] = graph[i][j];
            if (i != j && graph[i][j] != INF)
                nextHop[i][j] = j;
            else if (i == j && graph[i][j] == 0)
                nextHop[i][j] = i; 
            else
                nextHop[i][j] = -1;
        }
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (distance[i][k] != INF && distance[k][j] != INF &&
                    distance[i][k] + distance[k][j] < distance[i][j]) {
                    distance[i][j] = distance[i][k] + distance[k][j];
                    nextHop[i][j] = nextHop[i][k];
                }
            }
        }
    }

    printRoutingTable(distance, nextHop, n);
}

int main() {
    int n;
    printf("Enter the number of nodes or routers in the network: ");
    scanf("%d", &n);

    int graph[n][3];

    printf("Enter the weight or cost matrix:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0 && i != j)
                graph[i][j] = INF;  
        }
    }

    distanceVectorRouting(graph, n);

    return 0;
}




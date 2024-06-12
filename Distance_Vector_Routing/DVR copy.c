#include <stdio.h>
#include <limits.h>

#define MAX_NODES 10

int num_nodes;
int cost[MAX_NODES][MAX_NODES];
int distance[MAX_NODES][MAX_NODES];
char next_hop[MAX_NODES][MAX_NODES];

void initialize() {
    for(int i = 0; i < num_nodes; ++i) {
        for(int j = 0; j < num_nodes; ++j) {
            distance[i][j] = cost[i][j];
            if(i == j)
                next_hop[i][j] = i + 'A';
            else
                next_hop[i][j] = j + 'A';
        }
    }
}

void distance_vector_routing() {
    for(int k = 0; k < num_nodes; ++k) {
        for(int i = 0; i < num_nodes; ++i) {
            for(int j = 0; j < num_nodes; ++j) {
                if(distance[i][k] != INT_MAX && distance[k][j] != INT_MAX &&
                    distance[i][j] > distance[i][k] + distance[k][j]) {
                    distance[i][j] = distance[i][k] + distance[k][j];
                    next_hop[i][j] = next_hop[i][k];
                }
            }
        }
    }
}

void print_routing_table() {
    for(int i = 0; i < num_nodes; ++i) {
        printf("Final routing table of router %c:\n", 'A' + i);
        printf("Destination\tDistance\tNext_hop\n");
        for(int j = 0; j < num_nodes; ++j) {
            printf("%c\t\t%d\t\t%c\n", 'A' + j, distance[i][j], next_hop[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("Enter the number of nodes or routers in the network: ");
    scanf("%d", &num_nodes);

    printf("Enter the weight or cost matrix:\n");
    for(int i = 0; i < num_nodes; ++i) {
        for(int j = 0; j < num_nodes; ++j) {
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == -1) // Assuming -1 represents infinity
                cost[i][j] = INT_MAX;
        }
    }

    initialize();
    distance_vector_routing();
    print_routing_table();

    return 0;
}
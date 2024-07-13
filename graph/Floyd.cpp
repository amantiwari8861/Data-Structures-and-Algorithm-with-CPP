#include <iostream>
#include <vector>
#include <climits>

#define V 4  // Number of vertices in the graph
#define INF INT_MAX

using namespace std;

// Function to print the solution matrix
void printSolution(int dist[][V]) {
    cout << "The following matrix shows the shortest distances between every pair of vertices:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << "INF" << "\t";
            else
                cout << dist[i][j] << "\t";
        }
        cout << endl;
    }
}

// Function to implement Floyd-Warshall algorithm
void floydWarshall(int graph[][V]) {
    int dist[V][V];

    // Initialize the solution matrix same as the input graph matrix
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Add all vertices one by one to the set of intermediate vertices
    for (int k = 0; k < V; k++) {
        // Pick all vertices as source one by one
        for (int i = 0; i < V; i++) {
            // Pick all vertices as destination for the above-picked source
            for (int j = 0; j < V; j++) {
                // If vertex k is on the shortest path from i to j, then update the value of dist[i][j]
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest distance matrix
    printSolution(dist);
}

int main() {
    /* Let us create the following weighted graph
            10
       (0)------->(3)
        |         /|\
       5|          |
        |          | 1
       \|/         |
       (1)------->(2)
            3           */
    int graph[V][V] = {
        {0, 5, INF, 10},
        {INF, 0, 3, INF},
        {INF, INF, 0, 1},
        {INF, INF, INF, 0}
    };

    // Print the solution
    floydWarshall(graph);
    return 0;
}

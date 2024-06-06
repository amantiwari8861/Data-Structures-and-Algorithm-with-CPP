#include <iostream>
using namespace std;

class Graph
{
private:
    int size;
    int **adjMatrix;

public:
    // Constructor
    Graph(int n) : size(n)
    {
        // Dynamically allocate memory for the adjacency matrix
        adjMatrix = new int *[size];//row
        for (int i = 0; i < size; i++)
        {
            adjMatrix[i] = new int[size];
        }
        // Initialize the matrix with 0s
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                adjMatrix[i][j] = 0;
            }
        }
    }
    // Destructor to free memory
    ~Graph()
    {
        for (int i = 0; i < size; i++)
        {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
    }
    // Add edge function
    void addEdge(int i, int j)
    {
        adjMatrix[i][j] = 1; // Directed graph
        // For undirected graph, also add the edge in the opposite direction
        // adjMatrix[j][i] = 1;
    }

    // Remove edge function
    void removeEdge(int i, int j)
    {
        adjMatrix[i][j] = 0;
        // For undirected graph, also remove the edge in the opposite direction
        // adjMatrix[j][i] = 0;
    }

    // Print adjacency matrix
    void printAdjMatrix()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    // Create a graph with 5 vertices
    Graph graph(5);

    // Add edges
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);

    // Print the adjacency matrix
    cout << "Adjacency Matrix:" << endl;
    graph.printAdjMatrix();

    // Remove an edge
    graph.removeEdge(1, 2);

    // Print the adjacency matrix after removing an edge
    cout << "\nAdjacency Matrix after removing an edge:" << endl;
    graph.printAdjMatrix();

    return 0;
}
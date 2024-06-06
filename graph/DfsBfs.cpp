#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class Graph
{
private:
    int V;                   // Number of vertices
    vector<vector<int>> adj; // Adjacency list

    void DFSUtil(int v, vector<bool> &visited)
    {
        // Mark the current node as visited and print it
        visited[v] = true;
        cout << v << " ";

        // Recur for all the vertices adjacent to this vertex
        for (int i : adj[v])
        {
            if (!visited[i])
            {
                DFSUtil(i, visited);
            }
        }
    }

public:
    Graph(int V)
    {
        this->V = V;
        adj.resize(V);
    }

    // Function to add an edge to graph
    void addEdge(int v, int w)
    {
        adj[v].push_back(w); // Add w to v’s list.
        adj[w].push_back(v); // Since the graph is undirected
    }

    // DFS traversal of the vertices reachable from v
    void DFS(int v)
    {
        vector<bool> visited(V, false); // Mark all the vertices as not visited
        DFSUtil(v, visited);
    }

    // BFS traversal of the vertices reachable from v
    void BFS(int v)
    {
        vector<bool> visited(V, false); // Mark all the vertices as not visited
        queue<int> q;

        // Mark the current node as visited and enqueue it
        visited[v] = true;
        q.push(v);

        while (!q.empty())
        {
            // Dequeue a vertex from queue and print it
            v = q.front();
            cout << v << " ";
            q.pop();

            // Get all adjacent vertices of the dequeued vertex v
            // If an adjacent has not been visited, then mark it visited and enqueue it
            for (int i : adj[v])
            {
                if (!visited[i])
                {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }
};

int main()
{
    // Create a graph given in the above diagram
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(2, 5);
    g.addEdge(2, 6);
    g.addEdge(3, 4);

    cout << "Depth First Traversal starting from vertex 0:\n";
    g.DFS(0);

    cout << "\nBreadth First Traversal starting from vertex 0:\n";
    g.BFS(0);

    return 0;
}

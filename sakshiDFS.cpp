#include <iostream>
using namespace std;

int main()
{
    cout << "===== Program to demonstrate DFS Traversal on a Graph using Stack =====\n\n";

    int cost[10][10] = {0};      // Adjacency matrix
    int stk[10];                 // Stack for DFS
    int visited[10] = {0};       // Visited array

    int n, e, i, j, v;
    int top = -1;

    cout << "Enter the number of vertices (max 9): ";
    cin >> n;

    cout << "Enter the number of edges: ";
    cin >> e;

    cout << "Enter the start and end vertex of each edge (1-based indexing):\n";
    for (int k = 0; k < e; k++)
    {
        cin >> i >> j;
        cost[i][j] = 1;
        cost[j][i] = 1; // Assuming an undirected graph
    }

    cout << "Enter the starting vertex for DFS: ";
    cin >> v;

    // Push starting vertex to stack and mark visited
    stk[++top] = v;
    visited[v] = 1;

    cout << "\nDFS traversal is:\n";

    while (top != -1)
    {
        //Pop from stack
        v = stk[top];
        top--;
        cout << v << " ";

        // Check all adjacent vertices of v
        for (j = n; j >= 1; j--)
        {
            if (cost[v][j] == 1 && visited[j] == 0)
            {
                stk[++top] = j;
                visited[j] = 1;
            }
        }
    }

    cout << "\n";
    return 0;
}

#include <iostream>
#include <queue>
using namespace std;

#define MAX 50

struct node {
    int vertex;
    node *next;
};

node* adj[MAX];
bool visited[MAX]; // For BFS
queue<int> q;      // BFS queue
int n, val, nb;

// Function to create the graph
void create_graph() {
    cout << "Enter how many nodes are there in graph: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        cout << "Enter value of node " << i << ": ";
        cin >> val;

        node* nn = new node;
        node* last;

        nn->vertex = val;
        nn->next = NULL;

        adj[i] = last = nn;

        cout << "Enter how many nodes are connected to " << val << ": ";
        cin >> nb;

        for (int j = 1; j <= nb; j++) {
            cout << "Enter value of connected node: ";
            cin >> val;

            node* nn = new node;
            nn->vertex = val;
            nn->next = NULL;

            last->next = nn;
            last = nn;
        }
    }

    // Print adjacency list
    cout << "\nGraph in adjacency list format:\n";
    for (int i = 0; i < n; i++) {
        node* temp = adj[i];
        cout << "Node " << i << ": ";
        while (temp != NULL) {
            cout << temp->vertex << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
}

// Recursive BFS function
void BFS_recursive() {
    if (q.empty()) return;

    int current = q.front();
    q.pop();
    visited[current]=2;
    cout << current << " ";

    // Visit all unvisited neighbors
    node* temp = adj[current]->next; // Skip head node (self node)
    while (temp != NULL) {
        if (!visited[temp->vertex]) {
            visited[temp->vertex] = true;
            q.push(temp->vertex);
        }
        temp = temp->next;
    }

    BFS_recursive(); // Recursive call
}

// Main function
int main() {
    create_graph();

    int start;
    cout << "\nEnter starting node for BFS: ";
    cin >> start;

    // Initialize visited array
    for (int i = 0; i < MAX; i++)
        visited[i] = 0;

    // Start BFS
    visited[start] = 1;
    q.push(start);

    cout << "BFS Traversal (Recursive): ";
    BFS_recursive();
    cout << endl;

    return 0;
}

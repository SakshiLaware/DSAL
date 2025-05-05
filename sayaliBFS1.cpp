#include <iostream>
#include <queue>
using namespace std;

#define MAX 10

struct node {
    int vertex;
    node *next;
};

node* adj[50];
void create_graph();
int n, val, nb;

void create_graph()
{
    cout << "Enter how many nodes are there in graph: ";
    cin >> n;
    
   
    for (int i = 0; i < n; i++) 
    {
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

        for (int j = 1; j <= nb; j++)
        {
            cout << "Enter value of connected node: ";
            cin >> val;
            node* nn = new node;
            nn->vertex = val;
            nn->next = NULL;
            last->next = nn;
            last = nn;
        }
    }

   
    cout << "Graph in adjacency list format: " << endl;
    for (int i = 0; i < n; i++)     {
        node* temp = adj[i];
        cout << "Node " << i << ": ";
        while (temp != NULL)
        {
            cout << temp->vertex << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
}

int visited[50];  
int start;

void bfs()
{
   
    for (int i = 0; i < n; i++) 
    {
        visited[i] = 0; 
    }

    cout << "Enter root node: ";
    cin >> start;

    queue<int> q;  
    q.push(start);
    visited[start] = 1;  

    cout << "BFS traversal: ";
    node* temp;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        visited[node] = 2; 
        cout << node << " ";

        temp = adj[node];
        while (temp != NULL)
        {
            int n = temp->vertex;
            if (visited[n] == 0)  
            {
                q.push(n);
                visited[n] = 1;  
            }
            temp = temp->next;
        }
    }
    cout << endl;
}

int main()
{
    create_graph();
    bfs();
    return 0;
}

#include<iostream>
using namespace std;

#define max 10

class graph
{
    public:
    int g[max][max];
    int visited[max], n,e, i, j;
    
    void readg();
    void dfs(int);
};

void graph::readg()
{
    cout << "How many nodes: ";
    cin >> n;
    cout<<"Enter no of edges: ";
    cin>>e;
    
    cout << "Enter the start and end vertex of each edge (1-based indexing):\n";
    for (int k = 0; k < e; k++)
    {
        cin >> i >> j;
        g[i][j] = 1;
        g[j][i] = 1; // Assuming an undirected graph
    }
    
    
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    int v;
    cout << "Enter starting vertex (0 to " << n - 1 << "): ";
    cin >> v;
    
   
    dfs(v);
}

void graph::dfs(int i)
{   cout << i << " ";
    visited[i] = 1;
    for (int j = 0; j < n; j++)
    {
        if (visited[j] != 1 && g[i][j] == 1)
        {
            dfs(j);
        }
    }
}

int main()
{
    graph g;
    g.readg();
    return 0;
}

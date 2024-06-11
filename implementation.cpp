#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    int n;
    cout << "Enter the number of nodes: " << endl;
    cin >> n;

    vector<vector<int>> adj(n, vector<int>(n, 0));
    int e;
    cout << "Enter the number of edges: " << endl;
    cin >> e;

    for (int i = 0; i < e; i++)
    {
        /* code */
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            /* code */
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
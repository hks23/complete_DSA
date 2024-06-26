// KOSARAJU ALGORITHM 
#include <bits/stdc++.h>
using namespace std;
// template <typename T> // by this we can define datatype of T

class Graph
{
public:
    unordered_map<int, list<int>> adjList;

    void addEdge(int u, int v, bool direction)
    {
        // direction = 0 -> undirected graph
        // direction = 1 -> directed graph
        // create an edge from u to v
        adjList[u].push_back(v);
        if (direction == 0)
        {
            // undirected edge
            // create an edge from v to u
            adjList[v].push_back(u);
        }
    }

    void printAdjacencyList()
    {
        for (auto node : adjList)
        {
            cout << node.first << "-> ";
            for (auto neighbour : node.second)
            {
                // neighbour is traversing over the list
                cout << neighbour << ", ";
            }
            cout << endl;
        }
    }

    void dfs1(int src, stack<int> &s, unordered_map<int, bool> &vis)
    {
        vis[src] = true;
        for (auto nbr : adjList[src])
        {
            if (!vis[nbr])
            {
                dfs1(nbr, s, vis);
            }
        }
        s.push(src);
    }
    void dfs2(int src, unordered_map<int, bool> &visited, unordered_map<int, list<int>> adjNew)
    {
        visited[src] = true;
        cout<<src<<", ";
        for (auto nbr : adjNew[src])
        {
            if (!visited[nbr])
            {
                dfs2(nbr, visited, adjNew);
            }
        }
    }
    void SCC(int n)
    {
        unordered_map<int, bool> visited;
        stack<int> s;

        // find topo order
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs1(i, s, visited);
            }
        }

        // reverse the edges
        unordered_map<int, list<int>> adjNew;
        for (auto t : adjList)
        {
            for (auto nbr : t.second)
            {
                int u = t.first;
                int v = nbr;
                // insert new edge
                adjNew[v].push_back(u);
            }
        }

        // traverse the new graph and count
        int count = 0;
        unordered_map<int, bool> visited2;

        while (!s.empty())
        {
            int node = s.top();
            s.pop();
            if (!visited2[node])
            {
                cout<<"Printing "<<count+1<<" component ";
                dfs2(node, visited2, adjNew);
                cout<<endl;
                count++;
            }
        }
        cout <<"Number of components = "<< count <<endl;
    }
};

int main()
{
    Graph g;
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 0, 1);
    g.addEdge(2, 4, 1);
    g.addEdge(4, 5, 1);
    g.addEdge(5, 6, 1);
    g.addEdge(6, 4, 1);
    g.addEdge(6, 7, 1);

    cout << endl;
    g.printAdjacencyList();
    g.SCC(8);

    return 0;
}
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>
#include <list>
using namespace std;

template <typename T>
class Graph
{
public:
    unordered_map<T, list<T>> adjList;

    void addEdge(T u, T v, bool direction)
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
                cout << neighbour << ", ";
            }
            cout << endl;
        }
    }

    void shortestPathBfs(int src, int dest)
    {
        queue<int> q;
        unordered_map<int, bool> visited;
        unordered_map<int, int> parent;

        // initial steps for src
        q.push(src);
        visited[src] = 1;
        parent[src] = -1;

        while (!q.empty())
        {
            int fNode = q.front();
            q.pop();

            for (auto nbr : adjList[fNode])
            {   //push all neighbours which are un-visited
                if (!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = 1; //mark them true in visited array
                    parent[nbr] = fNode; //store the parent of node
                }
            }
        }

        // store path in ans after traversing in the parent array
        vector<int> ans;
        int node = dest;
        while (node != -1)
        { 
            ans.push_back(node);
            node = parent[node];
        }

        reverse(ans.begin(), ans.end());
        cout << "Printing ans: " << endl;
        for (auto it : ans)
        {
            cout << it << ", ";
        }
    }
};

int main()
{
    Graph<int> g;
    g.addEdge(0, 1, 0);
    g.addEdge(0, 6, 0);
    g.addEdge(0, 5, 0);
    g.addEdge(1, 2, 0);
    g.addEdge(2, 3, 0);
    g.addEdge(5, 4, 0);
    g.addEdge(4, 6, 0);
    g.addEdge(6, 2, 0);
    g.printAdjacencyList();

    g.shortestPathBfs(0, 4);
    return 0;
}

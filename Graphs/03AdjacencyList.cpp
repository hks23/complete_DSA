/*     an example of an undirected graph
            0 ---- 1
            |    / |
            |   /  |
            |  /   |
            3 -----2
Adjacency List will be
0 - {1,3}
1 - {0,2,3}
2 - {1,3}
3 - {1,2,0}

for weighted graph
store a pair inside the list { (node1, weight1) , (node2, weight2), (...,...)}
*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <string>
#include <list>
using namespace std;
template <typename T> // by this we can define datatype of T

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
                // neighbour is traversing over the list
                cout << neighbour << ", ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph<int> g;
    g.addEdge(0, 1, 0);
    g.addEdge(1, 2, 0);
    g.addEdge(0, 2, 0);
    cout << endl;
    g.printAdjacencyList();

    return 0;
}
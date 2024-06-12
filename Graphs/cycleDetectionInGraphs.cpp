/* 
Cycle detection
   /           \
Directed       Undirected
/      \         /      \
BFS      DFS   BFS      DFS
*/

// undirected Graph
//
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
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
    bool checkCyclicUsingBFS(int src, unordered_map<int, bool> &visited)
    {
        queue<int> q;
        unordered_map<int, int> parent;

        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while (!q.empty())
        {
            int frontNode = q.front();
            q.pop();

            for (auto neighbour : adjList[frontNode])
            {
                if (!visited[neighbour])
                {
                    q.push(neighbour);
                    visited[neighbour] = true;
                    parent[neighbour] = frontNode;
                }
                else
                {
                    // already visited
                    if (neighbour != parent[frontNode])
                    {
                        // cycle present
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool checkCyclicUsingDFS(int src, unordered_map<int, bool> &visited, int parent)
    {
        visited[src] = true;

        for (auto nbr : adjList[src])
        {
            if (!visited[nbr])
            {
                bool checkAageKaAns = checkCyclicUsingDFS(nbr, visited, src);
                if (checkAageKaAns == true)
                    return true;
            }
            if (visited[nbr] && nbr != parent)
            {
                // cycle present
                return true;
            }
        }
        return false;
    }

    // for directed graph checking cycle using DFS
    bool checkCyclicDirectedGraphUsingDfs(int src, unordered_map<int, bool> &visited,
                                          unordered_map<int, bool> &dfsVisited)
    {
        visited[src] = true;
        dfsVisited[src] = true;

        for (auto nbr : adjList[src])
        {
            if (!visited[nbr])
            {
                bool aageKaAnswer = checkCyclicDirectedGraphUsingDfs(nbr, visited, dfsVisited);
                if (aageKaAnswer == true)
                    return true;
            }
            if (visited[nbr] == true && dfsVisited[nbr] == true)
            {
                return true;
            }
        }

        dfsVisited[src] = false; // backtrack -> call stack moves out
        return false;
    }
};

int main()
{
    Graph<int> g;
    int n = 5;
    g.addEdge(1, 0, 1);
    g.addEdge(3, 1, 1);
    g.addEdge(0, 2, 1);
    g.addEdge(2, 4, 1);
    g.addEdge(4, 3, 1);

    g.printAdjacencyList();
    cout << endl;

    bool ansBFS = false;
    unordered_map<int, bool> visitedBFS;
    for (int i = 0; i < n; i++)
    {
        if (!visitedBFS[i])
        {
            ansBFS = g.checkCyclicUsingBFS(i, visitedBFS);
            if (ansBFS == true)
                break;
        }
    }
    if (ansBFS == true)
        cout << "Cycle is present (BFS)" << endl;
    else
        cout << "Cycle absent (BFS)" << endl;

    g.printAdjacencyList();

    bool ansDFS = false;
    unordered_map<int, bool> visitedDFS;
    for (int i = 0; i < n; i++)
    {
        if (!visitedDFS[i])
        {
            ansDFS = g.checkCyclicUsingDFS(i, visitedDFS, -1);
            if (ansDFS == true)
                break;
        }
    }
    if (ansDFS == true)
        cout << "Cycle is present (DFS)" << endl;
    else
        cout << "Cycle absent (DFS)" << endl;

    bool ansDirectedDFS = false;
    unordered_map<int, bool> visitedDirectedDFS;
    unordered_map<int, bool> dfsVisited;
    for (int i = 0; i < n; i++)
    {
        if (!visitedDirectedDFS[i])
        {
            ansDirectedDFS = g.checkCyclicDirectedGraphUsingDfs(i, visitedDirectedDFS, dfsVisited);
            if (ansDirectedDFS == true)
                break;
        }
    }
    if (ansDirectedDFS == true)
        cout << "Cycle is present in Directed Graph (DFS)" << endl;
    else
        cout << "Cycle absent in Directed Graph (DFS)" << endl;

    return 0;
}

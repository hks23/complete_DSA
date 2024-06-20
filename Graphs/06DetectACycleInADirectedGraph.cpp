/* Detect a loop/cycle in a directed graph
Requirements:
We need three things to store in this question.
1. An Adjacency List which holds all the neighbours
2. Visited Array which marks a node true if its visited
3. DFSvisited array which marks a value TRUE if dfs recursion call has been made for that node 

Algo.
If we find a node that is TRUE in both the Visited and the DFS Visited array then it means cycle is present
lets  say an example 
0 - 1 - 2 - 3 - 4
   / \     / '\'
  5 <- 6  7 -> 8

DRY RUN
dfs(0,-1) [set node 0 in dfsVisited as True]-> dfs(1,0) [set node 1 in dfsVisited as True] -> dfs(6,1) [..] -> dfs(5,6) 
now node 5 has nowhere to go base condition hit so this call dfs(5,6) moves out of call stack and we mark node 5
as FALSE again in dfsVisited array
*/

/* 
Cycle detection
   /           \
Directed       Undirected
/      \         /      \
BFS      DFS   BFS      DFS
*/
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
    // for directed graph checking cycle using DFS
bool checkCyclicDirectedGraphByDfs(int src,unordered_map<int,bool>&visited, unordered_map<int,bool>&dfsVisited)
    {
        visited[src] = true;
        dfsVisited[src] = true;

        for (auto nbr : adjList[src])
        {
            if (!visited[nbr])
            {
                bool aageKaAnswer = checkCyclicDirectedGraphByDfs(nbr, visited, dfsVisited);
                if (aageKaAnswer == true)
                    return true;
            }
            if (visited[nbr] == true && dfsVisited[nbr] == true)
            {
                return true;
            }
        }
        //yahi pe galti hogi
        dfsVisited[src] = false; // backtrack -> call stack moves out
        return false;
    }
};

int main()
{
    Graph<int> g;
    int n = 5;
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 1);
    g.addEdge(4, 0, 1);

    g.printAdjacencyList();

    bool ansDirectedDFS = false;
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            ansDirectedDFS = g.checkCyclicDirectedGraphByDfs(i, visited, dfsVisited);
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
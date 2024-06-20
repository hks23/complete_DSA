/*Steps to detect a cycle/loop in a graph
1. create a visited array
2. create a parent list which stores parent of a node
3. create an Adjacency list (like we did in program 03)

Algo.
1. Push the source node in queue 
2. Mark it true in visited array
3. using Adjacency List push its neighbouring nodes into the Queue
4. mark the parent of this node in the parent list
5. pop() the source node 

now repeat
1. Mark the current frontNode in queue as true 
2. push its neighbouring nodes in the queue only if they are marked as false ---if any neighbouring node is already set true then check kahi vo iska 
   parent to nahi hai agar parent hai to leave it varna we have detected a cycle
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

    void printAdjacencyList() {
		for(auto node: adjList) {
			cout << node.first << "-> " ;
			for(auto neighbour: node.second) {
				cout <<neighbour<<", ";
			}
			cout << endl;
		}
	}
    //USING BFS
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

            for (auto neighbour : adjList[frontNode]){
                if (!visited[neighbour])
                {
                    q.push(neighbour);
                    visited[neighbour] = true;
                    parent[neighbour] = frontNode;
                }
                else{
                    // already visited
                    if (neighbour != parent[frontNode]){
                        // cycle present
                        return true;
                    }
                }
            }
        }
        return false;
    }
    //Using DFS
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
};

int main()
{
    Graph<int> g;
    int n = 5;
    g.addEdge(0, 1, 0);
    g.addEdge(1, 2, 0);
    g.addEdge(2, 3, 0);
    g.addEdge(4, 0, 0);
    //g.addEdge(1, 4, 0);

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

    bool ansDFS = false;
    unordered_map<int, bool> visitedDFS;
    for (int i = 0; i < n; i++)
    {
        if (!visitedDFS[i])
        {
            ansDFS = g.checkCyclicUsingBFS(i, visitedDFS);
            if (ansDFS == true)
                break;
        }
    }
    if (ansDFS == true)
        cout << "Cycle is present (DFS)" << endl;
    else
        cout << "Cycle absent (DFS)" << endl;



}
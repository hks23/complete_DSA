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
    unordered_map<int, list<pair<int, int>>> adjList;

    void addEdge(int u, int v, int wt, bool direction)
    {
        // direction = 1 -> undirected graph
        // direction => 0 -> directed graph;
        adjList[u].push_back({v, wt});
        if (direction == 1)
        {
            adjList[v].push_back({u, wt});
        }
    }

    void printAdjList()
    {
        for (auto i : adjList)
        {
            cout << i.first << "-> ";
            for (auto j : i.second)
            {
                cout << "(" << j.first << ", " << j.second << "), ";
            }
            cout << endl;
        }
    }
    // assuming directed weighted graph
    void bellmannFordAlgo(int n, int src)
    {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        for (int i = 0; i < n - 1; i++)
        {
            // for all edges
            for (auto t : adjList)
            {
                for (auto nbr : t.second)
                {
                    int u = t.first;
                    int v = nbr.first;
                    int wt = nbr.second;
                    if (dist[u] != INT_MAX and dist[u] + wt < dist[v])
                    {
                        dist[v] = dist[u] + wt;
                    }
                }
            }
        }
        //to check for negative cycle
        bool negativeCycle = false;
        for (int i = 0; i < n - 1; i++)
        {
            // for all edges
            for (auto t : adjList)
            {
                for (auto nbr : t.second)
                {
                    int u = t.first;
                    int v = nbr.first;
                    int wt = nbr.second;
                    if (dist[u] != INT_MAX and dist[u] + wt < dist[v])
                    {
                        negativeCycle = true;
                        break;
                    }
                }
            }
        }
        if(negativeCycle == true){
            cout<<"Negative cycle is present no fixed solution possible"<<endl;
        }
        cout << "Printing dist array ";
        for (auto it : dist)
        {
            cout << it << ", ";
        }
    }
};

int main()
{
    Graph<int> g;
    g.addEdge(0, 1, -1, 0);
    g.addEdge(0, 2, 4, 0);
    g.addEdge(1, 2, 3, 0);
    g.addEdge(1, 3, 2, 0);
    g.addEdge(1, 4, 2, 0);
    g.addEdge(3, 1, 1, 0);
    g.addEdge(3, 2, 5, 0);
    g.addEdge(4, 3, -3, 0);

    // g.addEdge(4,3,11,1);
    // g.addEdge(6,5,9,1);
    // g.addEdge(4,5,6,1);

    g.printAdjList();
    for(int i =1 ; i<41; i++){
        cout<<i<<". "<<endl;
    }
    g.bellmannFordAlgo(5, 0);
    return 0;
}


// 1 B
// 2 D
// 5 C
// 6 C
// 14 B
// 15 B
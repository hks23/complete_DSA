// TARJAN'S ALGORITHM 
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
    void findBridges(int src, int parent, int&timer, vector<int>&tin, vector<int>&low, unordered_map<int,bool>vis){
        vis[src] = true;
        tin[src] = timer ;
        low[src] = timer ;
        timer++;
        for(auto nbr: adjList[src]){
            if(nbr == parent)
                continue;
            if(!vis[nbr]){
                //dfs call
                findBridges(nbr, src, timer, tin, low, vis);
                //low update
                low[src] = min(low[src], low[nbr]);
                //check for bridge
                if(low[nbr] > low[src]){
                    cout<<nbr<<"--"<<src<<" is a bridge"<<endl;
                }
            }
            else{
                //node is visited and not a parent
                //low update
                low[src] = min(low[src], low[nbr]);
            }
        }
    } 
};

int main()
{
    Graph g;
    g.addEdge(0, 1, 0);
    g.addEdge(0, 2, 0);
    g.addEdge(1, 2, 0);
    g.addEdge(3, 0, 0);
    g.addEdge(3, 4, 0);
   
    cout << endl;
    g.printAdjacencyList();
    int n = 5;
    int timer = 0;
    vector<int> tin(n);
    vector<int> low(n);
    unordered_map<int,bool> vis;
    g.findBridges(0, -1, timer, tin, low, vis);

    return 0;
}
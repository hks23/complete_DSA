#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>

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
                cout << neighbour << ", ";
            }
            cout << endl;
        }
    }

    // BFS - time complexity O(n + e) n=nodes e=edges
    // void bfs(int src) // but what if the graphs are disconnected hence we need to pass call for each node
    // {
    //     queue<int> q;
    //     unordered_map<int, bool> visited;

    //     q.push(src);
    //     visited[src] = true;

    //     while (!q.empty())
    //     {
    //         int frontNode = q.front();
    //         q.pop();
    //         cout << frontNode << ", ";

    //         // insert neighbours
    //         for (auto neighbour : adjList[frontNode])
    //         {
    //             if (!visited[neighbour])
    //             {
    //                 q.push(neighbour);
    //                 visited[neighbour] = true;
    //             }
    //         }
    //     }
    // }
    // void bfs1(int src, unordered_map<int, bool> &visited)
    // {
    //     queue<int> q;

    //     q.push(src);
    //     visited[src] = true;

    //     while (!q.empty())
    //     {
    //         int frontNode = q.front();
    //         q.pop();
    //         cout << frontNode << ", ";

    //         // insert neighbours
    //         for (auto neighbour : adjList[frontNode])
    //         {
    //             if (!visited[neighbour])
    //             {
    //                 q.push(neighbour);
    //                 visited[neighbour] = true;
    //             }
    //         }
    //     }
    // }
    // // DFS is like recursion
    // void dfs(int src, unordered_map<int, bool> &visited)
    // {
    //     cout << src << ", ";
    //     visited[src] = true;
    //     for (auto neighbour : adjList[src])
    //     {
    //         if (!visited[neighbour])
    //         {
    //             dfs(neighbour, visited);
    //         }
    //     }
    // }
};

int main()
{
    Graph<int> g;
    // g.addEdge(0, 1, 0);
    // g.addEdge(1, 2, 0);
    // g.addEdge(1, 3, 0);
    // g.addEdge(3, 5, 0);
    // g.addEdge(3, 7, 0);
    // g.addEdge(7, 6, 0);
    // g.addEdge(7, 4, 0);
    g.addEdge(0, 1, 0);
    g.addEdge(0, 2, 0);
    g.addEdge(1, 3, 0);
    g.addEdge(2, 4, 0);
    

    
    g.printAdjacencyList();
    cout << endl;
    // g.bfs(0);
    // cout << endl;

    // cout << "Printing BFS Traversal" << endl;
    // unordered_map<int, bool> visited;
    // for (int i = 0; i < 4; i++)
    // {
    //     if (!visited[i])
    //     {
    //         g.bfs1(i, visited); // in case of disconnected graph we need to call bfs method for each node
    //     }
    // }
    // cout<<endl;
    // cout << "Printing DFS Traversal" << endl;
    // unordered_map<int, bool> visited2;
    // for (int i = 0; i < 4; i++)
    // {
    //     if (!visited2[i])
    //     {
    //         g.dfs(i, visited2); // in case of disconnected graph we need to call bfs method for each node
    //     }
    // }
    return 0;
}

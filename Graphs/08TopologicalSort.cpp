// Linear ordering of vertices such that for every edge U -> V , U comes before V in that order
//  Topological sort can be done using BFS or DFS
// Topological sort can only be applied on Directed Acyclic Graph not in Cyclic graph

//Simple definition - vo node pehle aayegi jiski dependency khatam ho chuki hai
/*      0 -> 1 -> 2 -> 3 -> 5
                       |    |
                       4 -> 6 -> 7
*/

// for above example the topologica sort will be 0,1,2,3,5,4,6,7
//  LOGIC - go to each node and ask if that node has any dependency if yes go to that node and ask same ques
//  or store that value in a stack now pop all elements from stack and yahi hamara ans hai

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
// #include <stack>
// #include <unordered_map>
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

    void printAdjacencyList(){
        for (auto node : adjList){
            cout << node.first << "-> ";
            for (auto neighbour : node.second){
                cout << neighbour << ", ";
            }
            cout << endl;
        }
    }
    void dfs(int src, unordered_map<int, bool> &visited){
        cout << src << ", ";
        visited[src] = true;
        for (auto neighbour : adjList[src])
        {
            if (!visited[neighbour])
            {
                dfs(neighbour, visited);
            }
        }
    }
    void topoSortDFS(int src, unordered_map<int, bool> &visited, stack<int>&ans)
    {
        visited[src] = true;
        for (auto neighbour : adjList[src]){
            if (!visited[neighbour])
                topoSortDFS(neighbour, visited,ans);
        }
        //while returning, store the node in stack
        ans.push(src);
    }
    void topoSortBFS(int n, vector<int>&ans){
        queue<int> q;
        unordered_map<int, int> indegree;

        //calculate indegree using adjList
        for(auto i: adjList){
            int src = i.first;
            for(auto nbr: i.second){
                indegree[nbr]++;
            }
        }
        //put all nodes inside queue, which has indegree = 0
        for(int i=0; i<n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        //bfs logic
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            ans.push_back(frontNode);
            for(auto nbr: adjList[frontNode]){
                indegree[nbr]--;
                //check for Zero again
                if(indegree[nbr] == 0){
                    q.push(nbr);
                }
            }
        }
    }

};

int main()
{
    int n=8;
    Graph<int> g;
    g.addEdge(7, 1, 1);
    g.addEdge(4, 6, 1);
    g.addEdge(2, 4, 1);
    g.addEdge(3, 7, 1);
    g.addEdge(2, 5, 1);
    g.addEdge(5, 3, 1);
    g.addEdge(6, 7, 1);
    g.addEdge(7, 0, 1);
    g.printAdjacencyList();

    unordered_map<int , bool> visited;
    stack<int> ans;
    for(int i=0; i<n; i++){
        if(!visited[i])
            g.topoSortDFS(i,visited,ans);
    }

    cout<<"Topo Sort: DFS "<<endl;
    while(!ans.empty()){
        cout<<ans.top()<<", ";
        ans.pop();
    }

    cout<<endl<<"Topo Sort: BFS "<<endl;
    vector<int> ans2;
    g.topoSortBFS(n,ans2);
    for(auto it: ans2){
        cout<<it<<", ";
    }
    return 0;
}
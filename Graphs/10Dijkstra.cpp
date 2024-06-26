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
  unordered_map<int, list<pair<int,int> > > adjList;

	void addEdge(int u, int v, int wt, bool direction) {
		//direction = 1 -> undirected graph
		//direction => 0 -> directed graph;
		adjList[u].push_back({v,wt});
		if(direction == 1) {
			adjList[v].push_back({u,wt});
		}
	}

	void printAdjList() {
		for(auto i: adjList) {
			cout << i.first <<"-> ";
			for(auto j: i.second) {
				cout << "(" << j.first<<", "<<j.second<<"), ";
			}
			cout << endl;
		}
	}

	// Time Complexity O(elogv) e=edges v=vertices
    void shortestDistDijkstra(int src, int n) {
		vector<int> dist(n,INT_MAX);
		set<pair<int,int> > st;
		//intiial steps
		dist[src] = 0;
		st.insert(make_pair(0,src));

		while(!st.empty() ) {
			//fetch the smallest or first element from set
			auto topElement = *(st.begin()); // * is derefrence operator
			int nodeDistance = topElement.first;
			int node = topElement.second;

			//pop from set
			st.erase(st.begin());

				//neighbour traverse
			for(auto nbr: adjList[node]) {
				if(nodeDistance + nbr.second < dist[nbr.first]) {
					//mujhe distance update krna h 
					//finding entry in set
					auto result = st.find(make_pair(dist[nbr.first], nbr.first));
					//if found, then remove
					if(result != st.end()) {
						st.erase(result);
					}
					//updation in dist array and set
					dist[nbr.first] = nodeDistance + nbr.second;
					st.insert(make_pair(dist[nbr.first], nbr.first));
				}
			}
			
		}

		cout << "printing ans:" << endl;
		for(int i=0; i<n; i++) {
			cout << dist[i] <<", ";
		}
        cout << endl;
	}

};

int main()
{
    Graph<int> g;
    g.addEdge(6,3,2,1);
	g.addEdge(6,1,14,1);
	g.addEdge(3,1,9,1);
	g.addEdge(3,2,10,1);
	g.addEdge(1,2,7,1);
	g.addEdge(2,4,15,1);
	g.addEdge(4,3,11,1);
	g.addEdge(6,5,9,1);
	g.addEdge(4,5,6,1);
 

	g.printAdjList();

	g.shortestDistDijkstra(6,7);
    return 0;
}

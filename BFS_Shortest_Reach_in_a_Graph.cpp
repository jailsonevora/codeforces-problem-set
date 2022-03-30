#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include<climits>

using namespace std;

class Graph {
    public:
        vector<vector<pair<int,int>>> graph;
        
        Graph(int n) {
            graph.resize(n);
        }
    
        void add_edge(int u, int v) {
            graph[u].push_back({v,6});
            graph[v].push_back({u,6});
        }
    
        vector<int> shortest_reach(int start) {
            
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
            vector<int> distance(graph.size()+1, INT_MAX);
            pq.push({0,start});
            distance[start] = 0;
            
            while (!pq.empty()) {
                
                auto qU = pq.top();
                pq.pop();
                
                int u = qU.second;
                int distU = qU.first;
                
                for(auto qV: graph[u]){
                    
                    int v = qV.first;
                    int distV = qV.second;
                    
                    if(distance[v] < distance[u] + distV){
                        distance[v] = distance[u] + distV;
                        pq.push({distance[v],v});
                    }
                } 
            }
            
            for(int d: distance)
                if(distance[d] >= INT_MAX)
                    distance[d] = -1;
            return distance;
            
        }
    
};

int main() {
    int queries;
    cin >> queries;
        
    for (int t = 0; t < queries; t++) {
      
		int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6: 
        Graph graph(n);
        cin >> m;
        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            // add each edge to the graph
            graph.add_edge(u, v);
        }
		int startId;
        cin >> startId;
        startId--;
        // Find shortest reach from node s
        vector<int> distances = graph.shortest_reach(startId);

        for (int i = 0; i < distances.size(); i++) {
            if (i != startId) {
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}

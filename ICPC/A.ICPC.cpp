#include<iostream>
#include<vector>
#include <sstream>
#include <fstream>
 
using namespace std;
 
bool hasCycle(int u, vector<int> graph[], vector<int> &discovered, int count){
 
  if(discovered[u] == 1)
    return false;
  // processing
  if (discovered[u] == 2)
    return true;
 
  //mark the current node as processing
  discovered[u] = 2;
  
  // for every edge
  for(int v: graph[u]){
    count +=1;
    if(hasCycle(v, graph, discovered, count)){
        
      return true;
    }}
  discovered[u] = 1;
 
  return false;
}
 
int main() {
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int n;
    vector<int> edges(n+1);
 
    cin>>n;
 
    for(int i=1; i<=n; i++)
        cin>>edges[i];
 
    string ans = "NO";
 
    //create a graph
    vector<int> discovered(n+1, 0);
    vector<int> graph[n+1];
 
    for (int node = 1; node <= n; ++node)
      graph[node].push_back(edges[node]),
        graph[edges[node]].push_back(node);
 
    for (int node = 1; node < n; ++node)
        if(!discovered[node]) 
          if(hasCycle(node, graph, discovered,0))
            ans = "YES";
    cout << ans;
}
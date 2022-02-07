// DP Graph Problem
#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<numeric>

using namespace std;

bool dfs(int u, int dest, vector<int> graph[], vector<int>& visited){
    
    if(u == dest)
        return true;
    
    visited[u] = 1;
    for(int v: graph[u])
        if(!visited[v])
            if(dfs(v,dest,graph,visited))
                return true;
    return false;
}

void graph(int n, int v, vector<int> a){

    vector<int> graph[n];

    for(int edge = 0, u = 1; edge < a.size(); edge++, u++)
        graph[u].push_back(u+a[edge]);
    
    vector<int> visited(n,0);
    dfs(1,v,graph,visited) ? cout<<"Yes":cout<<"No";
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,v;
    cin>>n>>v;
    std::cin.ignore();

    int temp;
    string line;
    vector<int> a;

    getline(std::cin, line);
    istringstream ss(line);

    while (ss >> temp)
        a.push_back(temp);

    graph(n,v,a);
}

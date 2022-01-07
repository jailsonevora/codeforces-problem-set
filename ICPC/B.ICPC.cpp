#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>

using namespace std;

// find path compression
int _find(int v, vector<int>& parent){

    if(v == parent[v])
        return v;
    return parent[v] = _find(parent[v], parent); // path compression
}

// union by rank
void _union(int from, int to, vector<int>& parent, vector<int>& rank){
    
    if(rank[to] < rank[from])
        parent[to] = from;
    else if(rank[from] < rank[to])
        parent[from] = to;
    else
    {
        parent[to] = from;
        rank[from]++;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int n,m;
    //vector<int> event(n+1);
    //vector<int> graph[n+1];
    //unordered_map<int,pair<int,int>> graph;
 
    cin>> n >> m;

    vector<vector<int>> graph(n+1, vector<int>(n+1,0));
    // initialize leads
    vector<int> parent(n+1, 0);
    vector<int> rank(n+1, 0);

    
    // intantiate the rankings and parents
    for (int i = 0; i < n+1; i++)
        parent[i] = i, 
            rank[i] = 0;

    for(int i=1; i<=m; i++){
        int a, b, c;
	    cin >> a >> b >> c;
        if(a == 1){
            _union(b, c, parent, rank);
        }
        else{
            int absPFrom = _find(b, parent);
            int absPTo = _find(c, parent);
            
            if(absPFrom == absPTo)
                cout << "1";
            else
                cout << "0";
        }
    }
}
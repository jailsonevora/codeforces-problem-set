#include <bits/stdc++.h>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;


void dfs(int u, vector<int>& max, vector<int> graph[], vector<int> weigth, vector<int>& visited){

    visited[u] = 1;
    for(int v: graph[u])
        if(!visited[v])
            dfs(v, max, graph, weigth, visited);
    max.push_back(weigth[u]);

}

int solve(int n, vector<int> weigth, vector<int> nodes) {

    vector<int> graph[n+1];
    vector<int> indegree;

    for(int i=0; i < nodes.size(); i++){
        for(auto w: weigth){
            graph[i+1].push_back(nodes[i]);
            indegree[nodes[i]]++;
        }
    }

    vector<int> visited(n,-1), m;
    for (int u = 1; u < n; u++)
    {
        if(indegree[u] == 0){
            dfs(u,m,graph,weigth,visited);

        }
    }
    
    
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin>>t;
    for(int i=1; i <= t; ++i){
        
        int n;
        cin>>n;
        std::cin.ignore();

        int temp;
        string line;
        vector<int> weight;

        getline(std::cin, line);
        istringstream ss(line);

        while (ss >> temp)
            weight.push_back(temp); 

        int temp;
        string line;
        vector<int> nodes;

        getline(std::cin, line);
        istringstream ss(line);

        while (ss >> temp)
            nodes.push_back(temp);        
        
        cout << "Case #" << i << ": " << solve(n,weight,nodes) << endl;

        std::cin.clear();
    }
}
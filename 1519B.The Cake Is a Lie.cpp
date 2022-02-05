// Dynamic Programming DP on grid problem
#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<numeric>

using namespace std;
// DP tabulation
void bottomUp(int n, int m, int k){

    int dp[n][m];
    std::fill(dp[0],dp[n],0);

    for (int row = 0; row < n; row++)
        dp[row][0] = row;

    for (int col = 1; col < m; col++)
        dp[0][col] = col;

    for (int row = 1; row < n; row++)
        for (int col = 1; col < m; col++)
            dp[row][col] = dp[row-1][col] + (col+1);

    (dp[n-1][m-1] == k) ? cout << "Yes" : cout << "No"; 
    cout << endl; 
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    for(int i=1; i <= t; ++i){

        int n, m, k;
        cin>>n>>m>>k;
        
        bottomUp(n,m,k);
        std::cin.clear();
    }
    return 0;
}
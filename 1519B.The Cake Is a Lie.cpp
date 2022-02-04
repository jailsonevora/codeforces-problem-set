// Dynamic Programming DP on grid problem
#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<numeric>

using namespace std;
// m*n to 1,1
void bottomUp(int m, int n, int k){

    int dp[m][n];

    for (int row = 0; row < m; row++)
        dp[row][0] = 1;

    for (int col = 1; col < n; col++)
        dp[0][col] = 1;

    for (int row = 1; row < m; row++)
        for (int col = 1; col < n; col++)
            dp[row][col] = dp[row][col-1] + dp[row-1][col];
        
    (dp[m-1][n-1] == k) ? cout << "Yes" : cout << "No";    
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    for(int i=1; i <= t; ++i){

        int temp;
        string line;
        vector<int> items;

        getline(std::cin, line);
        istringstream ss(line);

        while (ss >> temp)
            items.push_back(temp);
        
        bottomUp(items[0],items[1],items[2]);
        std::cin.clear();
    }
    return 0;
}
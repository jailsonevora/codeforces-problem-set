#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

// Dynamic Programming Unbounded Knapsack problem
int bottomUp(long long amount){

    vector<int> bills = {1 , 5, 10, 20, 100};
    long long n = bills.size();
    //amount %=10;

    long long dp[n+1][amount+1];

    for(int row = 0; row <= n; ++row)
        dp[row][0] = 0;
    
    for(int col = 1; col <= amount; ++col)
        dp[0][col] = 1e5;

    for(int row = 1; row <= n; ++row)
        for(int col = 1; col <= amount; ++col){
            if(col < bills[row-1])
                dp[row][col] = dp[row-1][col];
            else
                dp[row][col] = min(1+dp[row][col-bills[row-1]], dp[row-1][col]);
        }
    return dp[n][amount] > 1e4 ? -1 : dp[n][amount];
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    long long n; 
    cin>> n;

    cout << bottomUp(n);
}
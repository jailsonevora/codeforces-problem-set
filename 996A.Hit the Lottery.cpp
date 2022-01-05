#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int bottomUp(int amount){

    vector<int> bills = {1 , 5, 10, 20, 100};
    int n = bills.size();

    int dp[n+1][amount+1];

    for(int row = 0; row <= n; ++row)
        dp[row][0] = 0;
    
    for(int col = 1; col <= amount; ++col)
        dp[0][col] = 1e5;

    

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int n; 
    cin>> n;

    return bottomUp(n);
}
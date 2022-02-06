// DP Fibonnacci Problem
#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<numeric>

using namespace std;

int fibonacciArmy(int n){

    int dp[] = {1,1};

    for (int i = 2; i <= n; i++)
        dp[i%2] = dp[0] + dp[1];

    return dp[n%2];
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    return fibonacciArmy(n);
}
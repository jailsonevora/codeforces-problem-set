// DP Fibonnacci Problem
#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<numeric>

using namespace std;

int fibonacciArmy(int n){

    int dp[] = {0,1,1};

    for (int i = 3; i < n; i++)
        dp[i%3] = dp[0] + dp[1];

    return dp[n%3];
}


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    cout << fibonacciArmy(n) << endl;
    return 0;
}
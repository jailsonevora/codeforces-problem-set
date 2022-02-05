// Dynamic Programming DP on grid problem
#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<numeric>

using namespace std;
// m*n to 1,1
void bottomUp(int n, int m, int k){

    int dp[n][m];
    std::fill(dp[0],dp[n],0);

    for (int row = 0; row < n; row++)
        for (int col = 0; col < m; col++){
            if(row==0 && col==0) 
                continue;
            if(row == 0)
                dp[row][col] = dp[row][col-1] + 1;
            else if(col == 0)
                dp[row][col] = dp[row-1][col] + 1;
            else
                dp[row][col] = dp[row-1][col] + (col+1);
        }
        
    (dp[n-1][m-1] == k) ? cout << "Yes" : cout << "No";    
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    for(int i=1; i <= t; ++i){

        std::cin.ignore();
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
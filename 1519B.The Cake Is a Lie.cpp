// Dynamic Programming DP on grid problem
#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<numeric>

using namespace std;
// m*n to 1,1
bool bottomUp(int m, int n, int k){

    int dp[m][n];

    for (int row = 1; i < count; i++)
    {
        /* code */
    }
    
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
// Dynamic Programming 0/1 Knapsack problem Subset sum
#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<numeric>

using namespace std;

bool bottomUp(vector<int> items, int n, int w){

    bool dp[n+1][w+1];

    for(int row = 0; row <= n; ++row)
        dp[row][0] = 1;

    for(int col = 1; col <= w; ++col)
        dp[0][col] = 0;

    for(int row = 1; row <= n; ++row)
        for(int col = 1; col <= w; ++col){
            if(col < items[row-1])
                dp[row][col] = dp[row-1][col];
            else
                dp[row][col] = (dp[row-1][col] || dp[row-1][col - items[row-1]]);
        }
    return dp[n][w];
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    for(int i=1; i <= t; ++i){
        
        int n;
        cin>>n;
        std::cin.ignore();

        int temp;
        string line;
        vector<int> items;

        getline(std::cin, line);
        istringstream ss(line);

        while (ss >> temp)
            items.push_back(temp);

        int w = 0;
        w = std::accumulate(items.begin(), items.end(), w);
        // if w has decimal part it is not possible to form subset
        if(w & 1){
            cout << "NO" << endl;
            continue;    
        }
        cout << (bottomUp(items,n, w/2) == 1 ? "YES" : "NO") << endl;
        std::cin.clear();
    }
    return 0;
}
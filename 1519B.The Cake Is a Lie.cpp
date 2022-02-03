// Dynamic Programming 0/1 Knapsack 
#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<numeric>

using namespace std;

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
        //cout << (bottomUp(items,n, w/2) == 1 ? "YES" : "NO") << endl;
        std::cin.clear();
    }
    return 0;
}
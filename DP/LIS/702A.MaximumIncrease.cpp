// DP Longest Increassing Subsequence or Greedy Problem
#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<numeric>

using namespace std;

int greedy(vector<int> items){

    if(items.size() == 1)
        return 1;

    int max = 0;
    for (int i = 1; i < items.size(); i++)
    {
        if(items[i] > items[i-1])
            max++;
        else
            max = 1;
    }
    return max;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

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

    cout << greedy(items) << endl;
    std::cin.clear();
    return 0;
}
// DP Longest Common Subsequence Problem Pattern Matching
#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<numeric>

using namespace std;

int lcs(string s, string p){

    int sz = s.size(), pz = p.size();

    int dp[sz+1][pz+1];
    int qaq = 0;

    for (int row = 0; row <= sz; row++)
        dp[row][0] = 0;
    for (int col = 1; col <= pz; col++)
        dp[0][col] = 0;

    for (int row = 1; row <= sz; row++)
        for (int col = 1; col <= pz; col++){
            if(s[row-1] == p[col-1])
                dp[row][col] = dp[row-1][col-1] + 1;
            else
                dp[row][col] = max(dp[row-1][col],dp[row][col-1]);

            if(dp[row][col] == pz)
                qaq++;
        }
    return qaq/pz;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s,p;
    cin>>s;
    
    p = "QAQ";
    cout << lcs(s,p);
}
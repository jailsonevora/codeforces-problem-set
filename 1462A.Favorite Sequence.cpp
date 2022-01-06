#include<iostream>
#include<algorithm>
#include<vector>
#include <sstream>

using namespace std;

vector<int> favoriteSequence(vector<int> sequence){

    vector<int> ans;
    int pointer1 = 0, pointer2 = sequence.size()-1;
    
    while(pointer1 <= pointer2){

        if(pointer1 == pointer2){
            ans.push_back(sequence[pointer1]); 
            break;
        }
        ans.push_back(sequence[pointer1]);
        ans.push_back(sequence[pointer2]);
        ++pointer1;
        --pointer2;
    }
    return ans;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    while(cin>>t){
        int n;
        cin>>n;

        int temp;
        string line;
        vector<int> sequence(n);

        getline(std::cin, line);
        istringstream ss(line);

        while (ss >> temp)
            sequence.push_back(temp);
            
        for(auto it: favoriteSequence(sequence))
            cout<<it<<" "<<
        endl;      
    }
    return 0;
}
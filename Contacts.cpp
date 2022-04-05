#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'contacts' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts 2D_STRING_ARRAY queries as parameter.
 */

struct TrieNode
{
    char c;
    int count;
    int endsWord;
    TrieNode* children[26];
};

TrieNode* root;

TrieNode *createNode(int index){
        
    TrieNode* newNode = new TrieNode;
    newNode->c = 'a'+index;
    newNode->count = newNode->endsWord = 0;
    
    for(int i = 0; i < 26; ++i)
        newNode->children[i] = nullptr;
    return newNode;
}

void insert(string word) {
        
    TrieNode *curr = root;

    int index;
    for (int i = 0; word[i] != '\0'; i++)
    {
        index = word[i]-'a';
        if(curr->children[index] == nullptr)
            curr->children[index] = createNode(index);
        curr->children[index]->count += 1;

        // increment
        curr = curr->children[index];
    }
    curr->endsWord += 1;
}

 bool startsWith(string prefix) {

    TrieNode *curr = root;

    int index;
    for (int i = 0; prefix[i] != '\0'; i++)
    {
        index = prefix[i]-'a';
        if(curr->children[index] == nullptr)
            return false;
        
        // increment 
        curr = curr->children[index];            
    }
    return curr->count > 0;        
}

vector<int> contacts(vector<vector<string>> queries) {

    for

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string queries_rows_temp;
    getline(cin, queries_rows_temp);

    int queries_rows = stoi(ltrim(rtrim(queries_rows_temp)));

    vector<vector<string>> queries(queries_rows);

    for (int i = 0; i < queries_rows; i++) {
        queries[i].resize(2);

        string queries_row_temp_temp;
        getline(cin, queries_row_temp_temp);

        vector<string> queries_row_temp = split(rtrim(queries_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            string queries_row_item = queries_row_temp[j];

            queries[i][j] = queries_row_item;
        }
    }

    vector<int> result = contacts(queries);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

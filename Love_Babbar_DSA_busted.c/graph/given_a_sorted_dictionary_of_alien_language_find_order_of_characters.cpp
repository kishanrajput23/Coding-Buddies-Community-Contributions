#include <bits/stdc++.h>
using namespace std;
#define inf INT_MAX
typedef pair<int, int> ipair;


// this is a simple question 
// just you need to identify that we need to do topological sort and need to make a adjacency list 
// this is done simply by two loop and checking normal dictionary by observation 
// doing topological sort to make them print. 
// time complexity: O(N*|S| + k)
// space complexity: O(N)
void dfs(int u,vector<int> &visited, vector<int> adj[], stack<int> &s ){
    visited[u] = 1;
    for(auto v: adj[u]){
        if(!visited[v]){
            dfs(v, visited, adj, s);
        }
    }
    s.push(u);
}

string alienLanguageCharacters(string dict[], int N, int k){
    vector<int> adj[k];

    for(int i = 0;i<N - 1;i++){
        string s1 = dict[i];
        string s2 = dict[i+1];
        for(int j = 0;j< min(s1.size(), s2.size());j++){
            if(s1[j] != s2[j]){
                adj[s1[j]- 'a'].push_back(s2[j]-'a');
                break;
            }
        }
    }

    // we see that the order is something similar to that of the topological sort. 
    // so I am doing topological sort with dfs. 
    vector<int> visited(k, 0);
    stack<int> s;
    for(int i = 0;i<k;i++)
    {
        if(!visited[i]){
            dfs(i, visited, adj, s);
        }
    }

    string st = "";
    while (!s.empty())
    {
        char temp = s.top() + 'a';
        s.pop();
        
        st = st+ temp;
    }
    return st;
}
int main()
{
    int N = 5;
    int k = 4;
    string dict[N] = {"baa", "abcd", "abca", "cab", "cad"};

    string res = alienLanguageCharacters(dict, N, k);
    cout<<res;
    return 0;
}
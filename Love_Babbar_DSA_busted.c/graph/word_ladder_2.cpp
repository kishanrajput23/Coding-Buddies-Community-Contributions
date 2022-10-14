#include <bits/stdc++.h>
using namespace std;

// HARD 
// this question is not present in love babbar sheet but it's important to do 
// this is the toughest question of the graphs and a very important and famous interview questiion. 
// time complexity: O((V+E) + (N*N*WordSize*26))
// space complexity: O(V)
// algo shortly: 
// first do bfs to create a adjacency list for tracking the elements 
// then do dfs for printing the paths.

// algo lengthy: 
// see tech dose video 
// code is written by me only by changing the word ladder 1 code. 
// see the copy notes . 
void dfs(unordered_map<string, vector<string>> &adj, vector<string> &path, string src, string &des, vector<vector<string>> &res)
{
    path.push_back(src);
    if (src == des)
    {
        res.push_back(path);
        path.pop_back();
        return;
    }

    for (auto x : adj[src])
    {
        dfs(adj, path, x, des, res);
    }
    path.pop_back();
}

vector<vector<string>> wordLadder(string beginW, vector<string> &v, string endW)
{
    //visited for maintaining the levels
    unordered_map<string, int> vis;

    //adj for the dfs traversal, we need to create this by bfs.
    unordered_map<string, vector<string>> adj;

    // for bfs
    queue<string> q;

    // for storing dictionary list.
    unordered_set<string> s;

    // from word ladder 1 no need of this .
    // int level = 0;

    // pushing the first word.
    q.push(beginW);

    // storing the size of each word.
    int Wsize = beginW.size();

    // inserting the elements from v to the s.
    for (int i = 0; i < v.size(); i++)
    {
        s.insert(v[i]);
    }

    // base condition.
    if (s.find(endW) == s.end())
    {
        return {};
    }

    // making first word letter level as zero .
    vis[beginW] = 0;

    // for bfs.
    while (!q.empty())
    {
        // level++;

        int csize = q.size();

        //**for debugging**
        // cout << csize << endl;

        for (int i = 0; i < csize; i++)
        {
            // string t is for the parent
            string t = q.front();

            // string curr is for the child.
            string curr = q.front();
            q.pop();

            for (int j = 0; j < Wsize; j++)
            {
                // so that the old string could be retained later.
                char temp = curr[j];
                for (char c = 'a'; c <= 'z'; c++)
                {
                    curr[j] = c;

                    // if found in the set.
                    if (s.find(curr) != s.end())
                    {
                        // if it is first time seen in the visited.
                        if (vis.count(curr) == 0)
                        {
                            //making levels ,pushing into the queue and creating the adj list.
                            vis[curr] = vis[t] + 1;
                            q.push(curr);
                            adj[t].push_back(curr);
                        }
                        // if it has a parent - child relationship.
                        else if (vis[curr] == vis[t] + 1)
                        {
                            // pushing into adj list
                            adj[t].push_back(curr);
                        }
                    }
                }
                // for retaining back the string.
                curr[j] = temp;
            }
        }
    }

    //** for debugging** printing the adj list.
    // for(auto x: adj)
    // {
    //     cout<<x.first<<"->";
    //     for(auto y: x.second)
    //     {
    //         cout<<y<<" ";
    //     }
    //     cout<<endl;
    // }

    // after creating the adj list do dfs to push all the paths in the resultant res vector<vector<string>>
    vector<string> path;
    vector<vector<string>> res;
    dfs(adj, path, beginW, endW, res);

    return res;
}

void printPaths(vector<vector<string>> &res)
{
    cout << "Number of possible paths are: " << endl;
    for (int i = 0; i < res.size(); i++)
    {
        cout << "Path number " << i + 1 << ": ";
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<string> v = {"hot", "dot", "lot", "dog", "log", "cog"};
    string beginW = "hit";
    string endW = "cog";
    vector<vector<string>> res = wordLadder(beginW, v, endW);
    printPaths(res);
    return 0;
}
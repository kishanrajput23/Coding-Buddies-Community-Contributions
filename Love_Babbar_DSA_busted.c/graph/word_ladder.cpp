#include <bits/stdc++.h>
using namespace std;

// AFTER THIS DO WORD LADDER 2 ALSO .
// this is a hard problem 
// A very important interview problem 
// see the explanation from tech dose or see the notes 
// check code from the code library. 
// time complexity: O(N*N*WordSize*26)
// space complexity: O(N)
// algo
// do bfs 
// while this check with the given condition 
int wordLadder(string beginW, vector<string> &v, string endW)
{
    // creating a queue
    queue<string> q;

    // marking the levels 
    int level = 0;

    // pushing the first word into the queue 
    q.push(beginW);

    // checking the size of each alphabet . 
    int Wsize = beginW.size();

    // creating a set to make find operation efficient. 
    unordered_set<string> s;
    for (int i = 0; i < v.size(); i++)
    {
        s.insert(v[i]);
    }

    // check the base condition if end word is not present 
    if (s.find(endW) == s.end())
    {
        return 0;
    }

    // simple bfs 
    while (!q.empty())
    {
        // increasing the size of the level 
        level++;

        // current size of the queue
        int csize = q.size();

        // traversing to check which all elements are adjacent and needed to be pushed into the queue. 
        for (int i = 0; i < csize; i++)
        {
            string t = q.front();
            q.pop();
            for (int j = 0; j < Wsize; j++)
            {
                char temp = t[j];
                for (char c = 'a'; c <= 'z'; c++)
                {
                    t[j] = c;
                    if (t == endW)
                    {
                        return level + 1;
                    }

                    if (s.find(t) != s.end())
                    {
                        s.erase(t);
                        q.push(t);
                    }
                }
                t[j] = temp;
            }
        }
    }
    return v.size() + 1;
}
int main()
{
    vector<string> v = {"hot", "dot", "lot", "dog", "log", "cog"};
    string beginW = "hit";
    string endW = "cog";
    int transformation = wordLadder(beginW, v, endW);
    cout<<transformation;
    return 0;
}
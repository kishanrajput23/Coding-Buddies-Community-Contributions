#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ipair;

// this problem is similar to that of the search in a maze but the difference lies here that 
// we need to do this problem by bfs as we need to find the shortest path. 
// concept is same as that of the search in a maze 
// appraoch by code library 
// code written myself some help of strivers code
// time complexity: O(V^2)
// space complexity: O(V^2)
int minSBKnight(ipair &s, ipair &t, int n)
{
    // because of 1 based indexing 
    s.first = s.first -1;
    s.second = s.second - 1;
    t.first = t.first-1;
    t.second = t.second -1;

    // for bfs 
    queue<ipair> q;

    //for tracking the distance similar to find the shortest distance in undirected unweighted graph 
    int cBoard[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cBoard[i][j] = 0;

    q.push({s.first, s.second});

    // possible moves by a knight . 
    int di[] = {-1, -2, -2, -1, +1, +2, +2, +1};
    int dj[] = {+2, +1, -1, -2, -2, -1, +1, +2};

    // normal bfs 
    while (!q.empty())
    {
        int i = q.front().first;
        int j = q.front().second;
        if (i == t.first && j == t.second)
            return cBoard[i][j];

        q.pop();
        for (int indx = 0; indx < 8; indx++)
        {
            int ni = i + di[indx];
            int nj = j + dj[indx];

            if (ni >= 0 && nj >= 0 && ni < n && nj < n && cBoard[ni][nj] == 0)
            {
                cBoard[ni][nj] = cBoard[i][j] + 1;
                q.push({ni, nj});
            }
        }
    }
    return cBoard[0][0];
}
int main()
{
    ipair s = {30, 30};
    ipair t = {1, 1};
    int n = 30;
    cout<<minSBKnight(s, t, n);
    return 0;
}
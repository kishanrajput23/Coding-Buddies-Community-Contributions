#include <bits/stdc++.h>
using namespace std;

// this quoestion is similar to the merge k sorted arrays 
// just now we need to maintain a max pointer and find out the range at each position. 
// then return that pair 
// time complexity: O(n*kLog(k)) n is the number of elements in a single vector
// space complexity: O(K)
struct triplet
{
    int ele;
    int x;
    int y;

    triplet(int a, int yc, int xc)
    {
        ele = a;
        x = xc;
        y = yc;
    }
};

struct myComp
{
    bool operator()(triplet &t1, triplet &t2)
    {
        return t1.ele > t2.ele;
    }
};

pair<int, int> rangeOfKLists(vector<vector<int>> &v)
{
    int maxvar = INT_MIN;
    priority_queue<triplet, vector<triplet>, myComp> pq;

    for (int i = 0; i < v.size(); i++)
    {
        triplet t(v[i][0], i, 0);
        pq.push(t);

        if (maxvar < v[i][0])
        {
            maxvar = v[i][0];
        }
    }

    int minrange = INT_MAX;
    pair<int, int> res;

    while (1)
    {
        triplet t = pq.top();
        pq.pop();
        int minvar = t.ele;
        int currrange = (maxvar - minvar);
        if (minrange > currrange)
        {
            res = make_pair(minvar, maxvar);
            // cout << minvar << " " << maxvar << endl;
            minrange = currrange;
            // cout << minrange << endl;
        }
        if (t.x + 1 < v[t.y].size())
        {
            triplet temp(v[t.y][t.x + 1], t.y, t.x + 1);
            pq.push(temp);

            if (temp.ele > maxvar)
            {
                maxvar = temp.ele;
            }
        }
        else
        {
            break;
        }
    }
    return res;
}

int main()
{
    vector<vector<int>> v;
    v = {{1, 2, 3, 4},
         {5, 6, 7, 8},
         {9, 10, 11, 12}};

    pair<int, int> p = rangeOfKLists(v);
    cout << p.first << " " << p.second;
    return 0;
}
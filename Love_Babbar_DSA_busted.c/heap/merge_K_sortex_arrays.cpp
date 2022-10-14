#include <bits/stdc++.h>
using namespace std;

// I had done this quoestion in gfg self placed course in topic heap
// there are three approaches to do this problem
// approach 1: create a temp array and push all of them and sort them
// approach 2: we know how to merge two sorted array , keep merging the two arrays till k times
// approach 3: the most efficient approach keep a heap with x, y, element. and then put all the first elements in the array and then keep printing the smallest element among all. and increment in that array
struct triplet
{
    int ele;
    int x;
    int y;
    triplet(int element, int yc, int xc)
    {
        ele = element;
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

vector<int> mergeKSorted(vector<vector<int>> &v)
{
    vector<int> res;
    priority_queue<triplet, vector<triplet>, myComp> q;
    for (int i = 0; i < v.size(); i++)
    {
        triplet t(v[i][0], i, 0);
        q.push(t);
    }

    while (!q.empty())
    {
        triplet t = q.top();
        res.push_back(t.ele);
        q.pop();
        if (t.x + 1 < v[t.y].size())
        {
            triplet temp(v[t.y][t.x + 1], t.y, t.x + 1);
            q.push(temp);
        }
    }
    return res;
}


int main()
{
    vector<vector<int>> v;
    v = {{2, 4, 9},
         {1, 5, 6},
         {3, 12}};
    vector<int> res = mergeKSorted(v);
    for(const auto x:res)
    {
        cout<<x<<" ";
    }
    return 0;
}
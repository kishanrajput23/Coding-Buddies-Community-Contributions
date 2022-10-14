#include <bits/stdc++.h>
using namespace std;

// I had already done this quoestion in heap folder in gfg self placed course
// time complexity: O(N*log(N))
// space compplexity: O(N)
vector<float> medainInAStream(int a[], int n)
{
    vector<float> res;
    priority_queue<int> M; // Max Heap
    priority_queue<int, vector<int>, greater<int>> m; // min Heap

    for (int i = 0; i < n; i++)
    {
        if(m.size()==0 and M.size() ==0)
        {
            M.push(a[i]);
        }
        else if(M.size() == m.size())
        {
            if(m.top()>a[i])
            {
                M.push(a[i]);
            }
            else if(m.top()<a[i])
            {
                int temp = m.top();
                m.pop();
                m.push(a[i]);
                M.push(temp);
            }
        }
        else if(M.size() == m.size() + 1)
        {
            if(M.top()>a[i])
            {
                int temp = M.top();
                M.pop();
                m.push(temp);
                M.push(a[i]);
            }
            else if(M.top()<a[i])
            {
                m.push(a[i]);
            }
        }

        int size = M.size() + m.size();

        if(size%2 ==0)
        {
            float temp = (M.top() + m.top())/2.0;
            res.push_back(temp);
        }
        else 
        {
            float temp = M.top();
            res.push_back(temp);
        }
    }
    return res;
}
int main()
{
    int a[] = {2, 4, 3, 9};
    int n = sizeof(a)/sizeof(int);

    vector<float> v = medainInAStream(a, n);

    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    
    return 0;
}
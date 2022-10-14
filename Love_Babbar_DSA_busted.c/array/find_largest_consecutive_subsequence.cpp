#include <bits/stdc++.h>
using namespace std;

// Question: find the longest subsequence in the array 
// algo
// store them in the set 
// then check a[i+1]- a[i]=1
// if so then increse the counter. 
// time commpelxity: O(N)
// space compelxity: O(N)
int largest_consecutive_subseq(int *a, int n)
{
    set<int> s(a, a+n);
    // sort(a, a + n);
    int maxcount = INT_MIN;
    int currcount = 1;
    int count = 0;
    for (auto it = s.begin(); it != s.end(); it++)
    {
        if(count==n-1){
            break;
        }
        auto temp = it;
        if ((*(++temp))-(*it) == 1)
        {
            currcount++;
        }
        else
        {
            maxcount = max(maxcount, currcount);
            currcount = 1;
        }
        count++;
    }
    // for (int i=0;i<n-1;i++)
    // {
    //     // int *temp = it++;
    //     if((a[i+1]-a[i])==1){
    //         currcount++;
    //     }
    //     else{
    //         maxcount = max(maxcount, currcount);
    //         currcount = 1;
    //     }
    // }
    maxcount = max(maxcount, currcount);
    return maxcount;
}
int main()
{
    int a[] =  {36, 41, 56, 35, 44, 33, 34, 92, 43, 32, 42};
    int n = sizeof(a) / sizeof(int);
    int b = largest_consecutive_subseq(a, n);
    cout<<b;

    // set<int> s(a, a + n);
    // for (auto i = s.begin(); i != s.end(); i++)
    // {
    //     cout<<*i<<endl;
    // }

    // auto it = s.begin();
    // auto temp = it;
    // cout<<(*(++temp))-(*it)<<" ";
    return 0;
}
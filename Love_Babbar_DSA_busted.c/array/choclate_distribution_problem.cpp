#include <bits/stdc++.h>
using namespace std;

// approach
// time complexity: O(Nlog(n))
// space complexity: O(1)
// An efficient solution is based on the observation that to minimize the difference, we must choose consecutive elements from a sorted packet
int choclateDistribution(int *a, int n, int m)
{
    if(n==0 || m==0){
        return 0;
    }

    if(n<m){
        return -1;
    }
    sort(a, a + n);
    int currmin = INT_MAX;
    for (int i = 0; i < n - m + 1; i++)
    {
        if (a[i + m - 1] - a[i] < currmin)
        {
            currmin = a[i + m - 1] - a[i];
        }
    }
    return currmin;
}
int main()
{
    int a[] ={7, 3, 2, 4, 9, 12, 56};
    int n = sizeof(a) / sizeof(int);
    int m = 3;
    cout<<choclateDistribution(a, n, m);
    return 0;
}
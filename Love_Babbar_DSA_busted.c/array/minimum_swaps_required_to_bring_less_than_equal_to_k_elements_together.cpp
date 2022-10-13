#include <bits/stdc++.h>
using namespace std;

// its a difficult revise from gfg and code library .
// by sliding window technique 
// time complexity: O(N)
// space complexity: O(1)
int minSwaps(int *a, int n, int k)
{
    int good = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] <= k)
        {
            good++;
        }
    }

    int bad = 0;
    for (int i = 0; i < good; i++)
    {
        if (a[i] > k)
        {
            bad++;
        }
    }

    int i = 0;
    int j = good-1;
    int ans = bad;
    //sliding window technique. 
    while (j < n)
    {
        j++;
        if (j==n)
        {
            break;
        }
        
        if (a[j] > k)
        {
            bad++;
        }

        if (a[i] > k)
        {
            bad--;
        }
        i++;
        ans = min(ans, bad);
    }

    return ans;
}

int main()
{
    int a[] = {4, 16, 3, 8, 13, 2, 19, 4, 12, 2, 7, 17, 4, 19, 1};
    int n = sizeof(a) / sizeof(int);
    int m = 9;
    cout << minSwaps(a, n, m);
    return 0;
}
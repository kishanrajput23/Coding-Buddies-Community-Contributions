#include <bits/stdc++.h>
using namespace std;
// This code runs in O(n) but I was not able to solve it but it's an very important question
// time complexity: O(N)
/// space complexity:O(1)
// see this code on geeks for geeks .

int minimiseMaxDiff(int *a, int n, int k)
{
    int maxEle, minEle;
    int res = a[n - 1] - a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] >= k)
        {
            maxEle = max(a[n - 1] - k, a[i - 1] + k);
            minEle = min(a[0] + k, a[i] - k);
            res = min(res, maxEle - minEle);
        }
        else
        {
            continue;
        }
    }
    return res;
}

int main()
{
    int arr[] = {1, 2, 3};
    int k = 2;
    int size = sizeof(arr) / sizeof(int);
    int a = minimiseMaxDiff(arr, size, k);

    cout << a << endl;
    return 0;
}
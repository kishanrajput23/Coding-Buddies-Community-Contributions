#include <bits/stdc++.h>
using namespace std;

// approach 1:
// time complexity: O(N^2)
// space complexity: O(1)
// check for all the subarrays if sum > x then check the minimum length.
// int smallestSubarrayWithSumGreaterThanX(int *a, int n, int x)
// {
//     int minimum = INT_MAX;
//     for (int i = 0; i < n; i++)
//     {
//         int sum = 0;
//         for (int j = i; j < n; j++)
//         {
//             sum += a[j];
//             if (sum > x)
//             {
//                 if ((j - i + 1) < minimum)
//                 {
//                     minimum = j - i + 1;
//                 }
//             }
//         }
//     }
//     return minimum;
// }

// approach2:
// two pointer algo
// see the video of code library 
// time complexity: O(N)
// space complexity: O(1)
int smallestSubarrayWithSumGreaterThanX(int *a, int n, int x)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > x)
        {
            return 1;
        }
        sum += a[i];
    }

    if (sum < x)
    {
        return -1;
    }

    int i = 0;
    int j = 1;
    int sumThem = a[0];
    int ans = INT_MAX;
    while (i < j && j < n)
    {
        sumThem += a[j];
        if (sumThem > x)
        {
            while (sumThem > x)
            {
                // if (j - i + 1 < ans)
                // {
                //     ans = j - i + 1;
                // }
                ans = min(ans, j - i + 1);
                sumThem -= a[i];
                i++;
            }
        }
        j++;
    }
    return ans;
}
int main()
{
    int a[] ={1, 2, 4};
    int n = sizeof(a) / sizeof(int);
    int m = 9;
    cout << smallestSubarrayWithSumGreaterThanX(a, n, m);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

// time complexity: O(N^2)
//space complexity: O(1)
// long long max_product_subarray(int *a, int n)
// {
//     long long finalMax = INT_MIN;
//     for (int i = 0; i < n; i++)
//     {
//         long long currprod = a[i];
//         for (int j = i + 1; j < n; j++)
//         {
//             finalMax = max(finalMax, currprod);
//             currprod *= a[j];
//         }
//         finalMax = max(finalMax, currprod);
//     }
//     return finalMax;
// }


// time complexity: O(N)
// space complexity: O(1)
// need to remember this approach
// take two vaiables max and min which store maximum product till that index and minimum product till that index respectively .
int max_product_subarray(int *a, int n)
{
    int maxProd = 1;
    int minProd = 1;
    int res = 1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0)
        {
            maxProd = maxProd * a[i];
            if (minProd * a[i] < 1)
            {
                minProd = minProd * a[i];
            }
            // minProd = min(1, minProd*a[i]);
        }
        else if (a[i] == 0)
        {
            maxProd = minProd = 1;
        }
        else
        {
            // if a[i]<0
            swap(maxProd, minProd);
            minProd = minProd * a[i];
            if (maxProd * a[i] > 1)
            {
                maxProd = maxProd * a[i];
            }
            // maxProd = max(1, maxProd*a[i]);
        }
        res = max(res, maxProd);
    }
    return res;
}
int main()
{
    int a[] = {0, 0, 0, 0};
    int n = sizeof(a) / sizeof(int);
    int p = max_product_subarray(a, n);
    cout << p;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

// approach1
// the algo says that for a specific bar to find how much water does it stores you need to find the biggest element among it's right and the smallest element among it's left ,
// then check out the minimum of them two and then subtract that value from the specific bar choosen.
// time complexity: O(N^2)
// space complexity: O(1)
// int rainwaterTrapping(int* a, int n){
//     int sum =0;
//     for (int j = 1; j < n-1; j++)
//     {
//         int maxhtL = a[j];
//         int maxhtR = a[j];
//         for (int i = 0; i < j; i++)
//         {
//             maxhtL = max(a[i], maxhtL);
//         }

//         for (int i = j+1; i < n; i++)
//         {
//             maxhtR = max(a[i], maxhtR);
//         }

//         sum += min(maxhtL, maxhtR)- a[j];
//     }

//     return sum;

// }

// approach 2:
// we could do some preprocessing by storing the largest left and largest right element in an auxillary array.
// time complexity: O(N)
// space complexity: O(N)
// this approach will work for the interview but we should also know approach which will take time : o(N) and space : O(1)
// int rainwaterTrapping(int *a, int n)
// {
//     int left[n];
//     int right[n];
//     int sum = 0;
//     // storing for left array
//     int msfl = a[0];
//     for (int i = 0; i < n; i++)
//     {
//         msfl = max(msfl, a[i]);
//         left[i] = msfl;
//     }

//     int msfr = a[n - 1];
//     for (int i = n - 1; i >= 0; i--)
//     {
//         msfr = max(msfr, a[i]);
//         right[i] = msfr;
//     }

//     for (int i = 0; i < n; i++)
//     {
//         sum += min(left[i], right[i]) - a[i];
//     }

//     return sum;
// }

// approach 3:
// two pointer approach
// time complexity: O(N)
// space complexity: O(1)
// see the video of tech dose for better understanding. 
int rainwaterTrapping(int *a, int n)
{
    int maxl = a[0];
    int maxr = a[n - 1];
    int l = 1;
    int r = n - 2;
    int sum = 0;
    while (l <= r)
    {
        if (maxl < maxr)
        {
            if (maxl <= a[l])
            {
                maxl = a[l];
            }
            else
            {
                sum += maxl - a[l];
            }
            l++;
        }
        else
        {
            if (maxr <= a[r])
            {
                maxr = a[r];
            }
            else
            {
                sum += maxr - a[r];
            }
            r--;
        }
    }
    return sum;
}
int main()
{
    int a[] = {7, 0, 0, 6, 5};
    int n = sizeof(a) / sizeof(int);
    cout << rainwaterTrapping(a, n);
    return 0;
}
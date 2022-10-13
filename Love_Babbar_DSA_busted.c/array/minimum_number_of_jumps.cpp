#include <bits/stdc++.h>
using namespace std;

// This code is  written by me and the Time Complexity is : O(n square)
int size(int *arr, int j, int k)
{
    int t = 0;
    for (int i = j; i < k; i++)
    {
        t++;
    }
    return t;
}

// time complexity: O(N^2)
// space complexity: O(N)
// int minJumps(int arr[], int n)
// {
//     // jumps[n-1] will hold the result
//     int *jumps = new int[n];
//     int i, j;

//     if (n == 0 || arr[0] == 0)
//         return INT_MAX;

//     jumps[0] = 0;

//     // Find the minimum number of jumps to reach arr[i]
//     // from arr[0], and assign this value to jumps[i]
//     for (i = 1; i < n; i++)
//     {
//         jumps[i] = INT_MAX;
//         for (j = 0; j < i; j++)
//         {
//             if (i <= j + arr[j] && jumps[j] != INT_MAX)
//             {
//                 jumps[i] = min(jumps[i], jumps[j] + 1);
//                 break;
//             }
//         }
//     }
//     return jumps[n - 1];
// }

// this is the best approach to solve this problem
// time complexity:O(N)
// space complexity:O(1)
int minJumps(int *a, int n)
{
    if (n <= 1)
    {
        return 0;
    }

    if (a[0] == 0)
    {
        return -1;
    }

    if (a[0] == 1 && a[1] == 0)
    {
        return -1;
    }

    int maxReach = a[0];
    int steps = a[0];
    int jumps = 1;
    for (int i = 1; i < n; i++)
    {
        if (i == (n - 1))
        {
            return jumps;
        }
        maxReach = max(maxReach, i + a[i]);
        steps--;
        if (steps == 0)
        {
            jumps++;
            if (i >= maxReach)
            {
                return -1;
            }
            steps = maxReach - i;
        }
    }
    return -1;
}
int main()
{
    int arr[] = {10, 8, 12, 17, 1, 21, 5, 17, 20, 11, 5, 27, 23, 8, 12, 18, 16, 12, 9, 8, 17, 12, 23, 26, 0, 5, 9, 24, 10};
    // int arr[] = {2, 1, 0, 3};
    int size = sizeof(arr) / sizeof(int);
    int m = minJumps(arr, size);
    printf("The minimum number of Jumps is %d \n", m);
    return 0;
}

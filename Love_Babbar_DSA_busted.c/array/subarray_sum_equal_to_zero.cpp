#include <bits/stdc++.h>
using namespace std;

// approach1:
// time complexity: o(N**3)
//space complexity: O(1)
int maxSubarray(int *arr, int size)
{
    int max = INT_MIN;
    int cursum = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            // int cursum=0;
            for (int k = i; k <= j; k++)
            {
                cursum += arr[k];
            }
            if (cursum == 0)
            {
                return 1;
            }
            cursum = 0;
        }
    }
    return max;
}

// approach 2:
// see geeks for geeks article for better understanding. 
// this is the most efficient approach to solve this problem
// use a map store the sum(from 0 to i) and value as it frequency if 
// frequency is greater than or equal to zero then print 1 else 0
// algorithm:
// the sum would repeat if we have a zero sum subarray
//We can also use hashing. The idea is to iterate through the array and for every element arr[i], calculate the sum of elements from 0 to i (this can simply be done as sum += arr[i]). If the current sum has been seen before, then there is a zero-sum array. Hashing is used to store the sum values so that we can quickly store sum and find out whether the current sum is seen before or not.

//time complexity: O(N)
// space complexity: O(N)
int maxSubarrayWithSumZero(int *a, int n)
{
    int sum = 0;
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        m[sum]++;
    }

    for (auto it = m.begin(); it != m.end(); it++)
    {
        if (it->second >= 2 || it->first ==0)
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    int arr[] = { 0};
    int size = sizeof(arr) / sizeof(int);
    int a = maxSubarrayWithSumZero(arr, size);
    // int a = maxSubarray(arr, size);
    if (a == 1)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
    return 0;
}
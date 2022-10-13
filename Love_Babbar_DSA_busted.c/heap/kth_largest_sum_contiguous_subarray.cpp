#include <bits/stdc++.h>
using namespace std;

// approach 1:
// time complexity: O(n^2)
// space complexity:O(2^n-1)
// this solution is best as per time complexity but very poor with the space complexity
// we might get out of memory with large arrays .
// int kthLargestSum(int *a, int n,int k)
// {

//     vector<int> sum;
//     int currsum = 0;
//     for (int i = 0; i < n; i++)
//     {
//         currsum = 0;
//         for (int j = i; j < n; j++)
//         {
//             currsum += a[j];
//             sum.push_back(currsum);
//         }
//     }
//     // for (int i = 0; i < sum.size(); i++)
//     // {
//     //     cout<<sum[i]<<" ";
//     // }

//     sort(sum.begin(), sum.end());
//     if(k>sum.size()) return -1;
//     return sum[sum.size()-k];
// }

// approach 2:
// this solution is better with space complexity but increases the time
// time complexity: O(N^2(log(K)))
// space complexity: O(K)
// this code is written by me not seen from anywhere 
// appraoch: 
// do not create an auxillary array to store the sum 
// use a min heap this concept is same as 'k largest elements in an array' 
// simply find all possible subarrays sum and find the kth largest. 
int kthLargestSum(int *a, int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> q;
    int currsum = 0;
    for (int i = 0; i < n; i++)
    {
        currsum = 0;
        for (int j = i; j < n; j++)
        {
            currsum += a[j];

            if (q.size() < k)
            {
                q.push(currsum);
            }
            else
            {
                if (q.top() < currsum)
                {
                    q.pop();
                    q.push(currsum);
                }
            }
        }
    }
    if(q.size()<k)
    {
        return -1;
    }
    return q.top();
}
int main()
{
    int a[] = {1, 2, 3, 4};
    int n = sizeof(a) / sizeof(int);
    int k = 10;
    int res = kthLargestSum(a, n, k);
    cout << res;

    return 0;
}
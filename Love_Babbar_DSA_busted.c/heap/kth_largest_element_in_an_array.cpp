#include <bits/stdc++.h>
using namespace std;

// I had already done this quoestion in arrays 
// but I am doing this quoestion again because I am restricted to solve this with heap
// although the best technique to do this question is with quick select algo

// time complexity: o(N + k*log(N))
// space complexity: O(N)
// similar can be done with kth minimum also 
int kthLargest(int *arr, int n, int k)
{
    priority_queue<int> q(arr, arr + n);
    k = k - 1;
    while (k--)
    {
        q.pop();
    }
    return q.top();
}
int main()
{
    int arr[] = {2, 3, 4, 5, 12, 45};
    int k = 2;
    int n = sizeof(arr) / sizeof(int);
    int klargest = kthLargest(arr, n, k);
    cout<<klargest;
    return 0;
}
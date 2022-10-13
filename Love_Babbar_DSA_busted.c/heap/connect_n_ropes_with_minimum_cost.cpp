#include <bits/stdc++.h>
using namespace std;

// done myself
// time complexity: O(N*log(N))
// space complexity: O(N)
int minCost(int *arr, int n)
{
    priority_queue<int, vector<int>, greater<int>> q(arr, arr + n);
    int sum = 0;
    while (q.size() != 1)
    {
        int a = q.top();
        q.pop();
        int b = q.top();
        q.pop();
        int temp = a + b;
        q.push(temp);
        sum += temp;
    }
    return sum;
}

int main()
{
    int arr[] = {4, 2, 7, 6, 9};
    int n = sizeof(arr) / sizeof(int);
    int res = minCost(arr, n);
    cout << res;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
// its just similar to the sliding window maximum problem 
// just we need to change the sign of greater than or equal to the less than or equal to 

//  TIME COMPLEXITY: O(N)
// SPACE COMPLEXITY: O(K)

void printMaximumElementOfWindowSizeK(int arr[], int n, int k)
{
    deque<int> q;
    int i;
    for (i = 0; i < k; i++)
    {

        while ((!q.empty()) && (arr[i] >= arr[q.back()]))
        {
            q.pop_back();
        }
        q.push_back(i);
    }

    for (; i < n; i++)
    {
        cout << arr[q.front()] << " ";

        while ((!q.empty()) && (q.front() <= (i - k)))
        {
            q.pop_front();
        }

        while ((!q.empty()) && (arr[i] >= arr[q.back()]))
        {
            q.pop_back();
        }
        q.push_back(i);
    }
    cout<<arr[q.front()]<<" ";
}
int main()
{
    int arr[] = {12, 1, 78, 90, 57, 89, 56};
    int n = sizeof(arr) / sizeof(int);
    int k = 3;
    printMaximumElementOfWindowSizeK(arr, n, k);
}
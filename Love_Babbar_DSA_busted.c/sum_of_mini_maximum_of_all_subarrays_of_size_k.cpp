#include <bits/stdc++.h>
using namespace std;
// it's a difficult level question it's a mix of sliding window maximum and sliding window minimum 
// just we need to sum the maximum and the minimum element 
// time complexity: O(N)
// space complexity: O(k)
int sum_of_mini_max_of_all_subarrays_of_size_k(int arr[], int n, int k)
{
    int sum = 0;
    int i;
    deque<int> M;
    deque<int> m;

    for (i = 0; i < k; i++)
    {
        while ((!M.empty()) && (arr[i] >= arr[M.back()]))
        {
            M.pop_back();
        }
        while ((!m.empty()) && (arr[i] <= arr[m.back()]))
        {
            m.pop_back();
        }
        M.push_back(i);
        m.push_back(i);
    }

    for (; i < n; i++)
    {
        sum += (arr[M.front()] + arr[m.front()]);

        while ((!M.empty()) && (M.front() <= (i - k)))
        {
            M.pop_front();
        }
        while ((!m.empty()) && (m.front() <= (i - k)))
        {
            m.pop_front();
        }

        while ((!M.empty()) && (arr[i] >= arr[M.back()]))
        {
            M.pop_back();
        }
        while ((!m.empty()) && (arr[i] <= arr[m.back()]))
        {
            m.pop_back();
        }
        M.push_back(i);
        m.push_back(i);
    }
    sum += (arr[M.front()] + arr[m.front()]);
    return sum;
}
int main()
{
    int arr[] = {2, 5, -1, 7, -3, -1, -2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    int sum = sum_of_mini_max_of_all_subarrays_of_size_k(arr, n, k);
    cout<<sum;
    return 0;
}




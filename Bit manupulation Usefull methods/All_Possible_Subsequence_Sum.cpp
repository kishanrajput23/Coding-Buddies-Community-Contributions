#include <bits/stdc++.h>
using namespace std;

// This is brute force approach
// Time complexity: O(2^n)
// Space complexity: O(n^2)
void function1(vector<int> arr, int n)
{
    // declare a vector to store all possible subsequence sum
    vector<int> subsequenceSum;

    // run a loop for 2^n times
    for (int mask = 0; mask < (1 << n); mask++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            if (mask & (1 << j))
            {
                sum += arr[j];
            }
        }
        subsequenceSum.push_back(sum);
    }

    // print all possible subsequence sum
    for (auto x : subsequenceSum)
    {
        cout << x << " ";
    }
}
int main()
{
    vector<int> arr = {1, 2, 3};
    int n = arr.size();
    function1(arr, n);

    return 0;
}
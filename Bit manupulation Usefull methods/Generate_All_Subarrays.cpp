#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr = {1, 2, 3};
    int n = arr.size();
    vector<vector<int>> subarray;

    for (int mask = 0; mask < (1 << n); mask++)
    {
        vector<int> temp;
        for (int j = 0; j < n; j++)
        {
            if (mask & (1 << j))
            {
                temp.push_back(arr[j]);
            }
        }
        subarray.push_back(temp);
    }

    for (auto i : subarray)
    {
        cout << "{ ";
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}
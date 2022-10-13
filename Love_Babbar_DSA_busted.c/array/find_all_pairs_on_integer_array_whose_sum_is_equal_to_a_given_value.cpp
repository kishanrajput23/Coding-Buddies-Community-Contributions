#include <bits/stdc++.h>
using namespace std;

// approach 1:
// time complexity: O(N**2)
// space complexity: O(1)
int getPairsCount(int arr[], int n, int sum)
{
    int count = 0; // Initialize result

    // Consider all possible pairs and check their sums
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] + arr[j] == sum)
                count++;

    return count;
}

// approach 2: this is the best approach to solve this
// time complexity: O(N)
// space complexity: O(N)
// use map
// store the key as element and value as frequency of each array
// as searching takes only O(1) in map so traverse through the array
// and then search for each k- a[i] element and then add to your count of its frequency .
int sumWithGivenValue(int *a, int n, int k)
{
    int count = 0;
    map<int, int> m;

    // no need to write this as map memebers for int are already inititalized to the zero  .
    // for (int i = 0; i < n; i++)
    // {
    //     m[a[i]]= 0;
    // }

    //     n = 6, X = 13
    // arr[] = [1 4 45 6 10 8]

    for (int i = 0; i < n; i++)
    {
        m[a[i]]++;
    }

    for (int i = 0; i < n; i++)
    {
        int temp = k - a[i];
        if (m.find(temp) != m.end())
        {
            count += m[temp];
        }
        if (temp == a[i])
        {
            count--;
        }
    }

    return count / 2;
}

int main()
{
    int a[] = {1, 1, 1, 1};
    int n = sizeof(a) / sizeof(int);
    int k = 2;
    cout << sumWithGivenValue(a, n, k);
    return 0;
}
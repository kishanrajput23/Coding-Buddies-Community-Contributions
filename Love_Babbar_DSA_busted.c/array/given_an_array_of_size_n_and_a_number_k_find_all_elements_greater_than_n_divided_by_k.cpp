#include <bits/stdc++.h>
using namespace std;

// Given an array of size n and a number k, find all elements that appear more than n/k times

// approach1:
// time complexity: O(N^2)
// space complexity: O(N) using set to store distinct elements .
// void greater_than_n_by_k(int *a, int n, int k)
// {
//     set<int> s;
//     for (int i = 0; i < n; i++)
//     {
//         int count = 1;
//         for (int j = i + 1; j < n; j++)
//         {
//             if (a[i] == a[j])
//             {
//                 count++;
//             }
//         }
//         if (count > (n / k))
//         {
//             s.insert(a[i]);
//         }
//     }
//     for (auto i = s.begin(); i != s.end(); i++)
//     {
//         cout << (*i) << " ";
//     }
// }

// approach 2:
// time complexity: O(Nlog(N))
// space complexity: O(1)
// void greater_than_n_by_k(int *a, int n, int k)
// {
//     sort(a, a + n);
//     int count = 1;
//     for (int i = 0; i < n - 1; i++)
//     {
//         if (a[i] == a[i + 1])
//         {
//             count++;
//             if (count > (n / k))
//             {
//                 cout << a[i] << " ";
//             }
//         }
//         else
//         {
//             count = 1;
//         }
//     }
// }

// approach 3:
// time complexity: O(N)
// space complexity: O(N)
void greater_than_n_by_k(int *a, int n, int k)
{
    map<int, int> m;
    int count = 1;
    for (int i = 0; i < n; i++)
    {
        if (m.find(a[i]) != m.end())
        {
            m[a[i]]++;
        }
        else
        {
            m[a[i]] = count;
        }
    }
    for (auto it = m.begin(); it != m.end(); it++)
    {
        if (it->second > (n / k))
        {
            cout << it->first << " ";
        }
    }
}


int main()
{
    int a[] = {3, 2, 2, 1, 1, 2, 3, 3};
    int n = sizeof(a) / sizeof(int);
    int k = 4;
    greater_than_n_by_k(a, n, k);
    return 0;
}
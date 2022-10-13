#include <bits/stdc++.h>
using namespace std;

// approach 1:
// time complexity: O(N^3)
// space complexity: O(1)
// bool tripletCount(int *a, int n, int x)
// {
//     for (int i = 0; i < n - 2; i++)
//     {
//         for (int j = i + 1; j < n - 1; j++)
//         {
//             for (int k = j + 1; k < n; k++)
//             {
//                 if (a[i] + a[j] + a[k] == x)
//                 {
//                     return true;
//                 }
//             }
//         }
//     }
//     return false;
// }

// approach2: I have used here map as the data structure we could also use set data structure whose code is written approach3
// time complexity: O(N^2)
// space complexity: O(N)
// bool tripletCount(int *a, int n, int x)
// {
//     for (int i = 0; i < n; i++)
//     {
//         int k = x - a[i];
//         map<int, int> m;
//         int j;
//         for ( j = 0; j < n; j++)
//         {
//             if (i == j)
//             {
//                 continue;
//             }
//             m[a[i]]++;
//         }

//         for ( j = 0; j < n; j++)
//         {
//             if (i == j)
//             {
//                 continue;
//             }
//             int temp = k - a[j];
//             if (m.find(temp) != m.end())
//             {
//                 if (temp == a[j])
//                 {
//                     continue;
//                 }
//                 return true;
//             }
//         }
//     }
//     return false;
// }

// approach 3: used set data structure
// time compelxity: O(N^2)
// space complexity: O(N)
// bool tripletCount(int *a, int n, int x)
// {
//     for (int i = 0; i < n - 2; i++)
//     {
//         unordered_set<int> s;
//         int temp = x - a[i];
//         for (int j = i + 1; j < n; j++)
//         {
//             if (s.find(temp - a[j]) != s.end())
//             {
//                 return true;
//             }
//             s.insert(a[j]);
//         }
//     }
//     return false;
// }

// approach 4: two - pointer algo
// time complexity: O(N^2)
// space complexity: O(1)
bool tripletCount(int *a, int n, int x)
{
    for (int i = 0; i < n - 2; i++)
    {
        int l = i + 1;
        int h = n - 1;
        while (l < h)
        {
            if (a[i] + a[l] + a[h] == x)
            {
                return 1;
            }
            else if (a[i] + a[l] + a[h] < x)
            {
                l++;
            }
            else
            {
                h--;
            }
        }
    }
    return 0;
}
int main()
{
    int a[] = {1, 2, 4, 3, 6};
    int n = sizeof(a) / sizeof(int);
    int x = 9;
    if (tripletCount(a, n, x))
    {
        cout << "1";
    }
    else
    {
        cout << "0";
    }
    return 0;
}
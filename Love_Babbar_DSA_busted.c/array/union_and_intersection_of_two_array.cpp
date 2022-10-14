#include <bits/stdc++.h>
using namespace std;
// Find union and intersection of the two arrays

// approach 1: sort these two unsorted arrays and then use two pointer approach to solve the problem similar to merge sort
// time complexity: O((n+m) + nlogn + mlogm)  ===> O(nlogn + mlogm)
// space complexity: O(1)
void union_of_two_array(int *a, int n, int *b, int m)
{
    sort(a, a + n);
    sort(b, b + m);
    int i = 0;
    int j = 0;
    while (i <= (n - 1) and j <= (m - 1))
    {
        if (a[i] > b[j])
        {
            cout << b[j] << " ";
            j++;
        }
        else if (a[i] < b[j])
        {
            cout << a[i] << " ";
            i++;
        }
        else
        {
            cout << a[i] << " ";
            j++;
            i++;
        }
    }
    while (i < n)
    {
        cout << a[i] << " ";
        i++;
    }
    while (j < m)
    {
        cout << b[j] << " ";
        j++;
    }
}

// approach 2: using set as set stores the distinct elemets.
// time complexity: O(N+M)
// space complexity: O(N+M)
// void union_of_two_array(int* a, int n, int* b, int m){
//     set<int> s;

//     for (int i = 0; i < n; i++)
//     {
//         s.insert(a[i]);
//     }
//     for (int i = 0; i < m; i++)
//     {
//         s.insert(b[i]);
//     }

//     for (auto it = s.begin(); it != s.end(); it++)
//     {
//         cout<<*it<<" ";
//     }

// }

// approach 3: use map as key are unique in a map
// time complexity: o(N+M)
// space complexity: O(N+M)

// void union_of_two_array(int a[], int n, int b[], int m){
//     // key: array elements , value: indexes
//     map<int, int> mp;

//     for (int i = 0; i < n; i++)
//     {
//         mp.insert({a[i], i});
//     }

//     for (int j = 0; j < m; j++)
//     {
//         mp.insert({b[j], j});
//     }

//     for (auto it = mp.begin(); it != mp.end(); it++)
//     {
//         cout<<it->first<<" ";
//     }
// }

// INTERSECTION OF TWO ARRAYS
// approach 1: sort the two arrays and then use the merge sort algo. to print the common elements
// time complexity: O(nlogn + mlogm + (n+m)) ==> O(nlogn + mlogm)
// space complexity: O(1)
// void intersection_of_two_arrays(int *a, int n, int *b, int m)
// {
//     sort(a, a + n);
//     sort(b, b + m);

//     int i = 0;
//     int j = 0;

//     while (i < n && j < m)
//     {
//         if (a[i] < b[j])
//         {
//             i++;
//         }
//         else if (a[i] > b[j])
//         {
//             j++;
//         }
//         else
//         {
//             cout << a[i] << " ";
//             i++;
//             j++;
//         }
//     }
// }


// approach use map as finding in map is in O(1)
// store the first arrays value into the map
// then, iterate through the second array and find weather that element is present in the map if yes then 
// print that element and remove that from the map . 
// time complexity: O(N + M)
// space complexity: O(N + M)
void intersection_of_two_arrays(int *a, int n, int *b, int m)
{
    map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        mp[a[i]] = i;
    }

    for (int i = 0; i < m; i++)
    {
        // map<int, int>:: iterator iter = mp.find(b[i]);
        auto iter = mp.find(b[i]);
        if (iter != mp.end())
        {
            cout << b[i] << " ";
            mp.erase(iter);
        }
    }
}
int main()
{
    int a[] = {1, 2, 1, 1, 2};
    int n = sizeof(a) / sizeof(int);
    int b[] = {1, 4, 7};
    int m = sizeof(b) / sizeof(int);

    // union_of_two_array(a, n, b, m);
    intersection_of_two_arrays(a, n, b, m);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

void print_first_negative(int arr[], int n, int k)
{
    int i;
    deque<int> q;
    int zero = 0;
    for (i = 0; i < k; i++)
    {
        if (arr[i] < 0)
        {
            q.push_back(i);
        }
    }

    for (; i < n; i++)
    {
        if (!q.empty())
        {
            cout << arr[q.front()] << " ";
        }
        else
        {
            cout << zero << " ";
        }

        while ((!q.empty()) && (q.front() <= (i - k)))
        {
            q.pop_front();
        }

        if (arr[i] < 0)
        {
            q.push_back(i);
        }
    }
    if (!q.empty())
    {
        cout << arr[q.front()] << " ";
    }
    else
    {
        cout << zero << " ";
    }
}

int main()
{
    int arr[] = {-8, 2, 3, -6, 10};
    int n = sizeof(arr) / sizeof(int);
    int k = 2;
    print_first_negative(arr, n, k);
    return 0;
}

// // #include <bits/stdc++.h>
// // using namespace std;

// // // write a program to find the the first negative integer in every window of size k
// // // this is brute force approach written by me
// // // time complexity: O(N*k)
// // // space complexity: O(1)
// // int main()
// // {
// //     int arr[] = {12, -1, -7, 8, -15, 30, 16, 28};
// //     int n = sizeof(arr) / sizeof(int);
// //     int k = 6;
// //     int zero = 0;
// //     for (int i = 0; i < n - k+1; i++)
// //     {
// //         int count = 0;
// //         for (int j = i; j < (k + i); j++)
// //         {
// //             if (arr[j] < 0)
// //             {
// //                 cout << arr[j] << " ";
// //                 count++;
// //                 break;
// //             }
// //         }
// //         if (count == 0)
// //         {
// //             cout << zero << " ";
// //         }
// //     }
// //     return 0;
// // }

// #include <bits/stdc++.h>
// using namespace std;
// // this is the optimised approach made by me using queue
// // time complexity: O(N)
// // space complexity: O(K)

// int main()
// {
//     int arr[] = {12, -1, -7, 8, -15, 30, 16, 28};
//     int n = sizeof(arr) / sizeof(int);
//     int k = 3;
//     int zero = 0;
//     queue<int> q;

//     for (int i = 0; i < (n - k + 1); i++)
//     {
//         int j = i;
//         while (q.size() != k)
//         {
//             q.push(arr[j]);
//             j++;
//         }

//         while (1)
//         {
//             if((q.front()<0)  || (q.empty())){
//                 break;
//             }
//             q.pop();
//         }

//         if (!q.empty())
//         {
//             cout << q.front() << " ";
//             while(!q.empty()){
//                 q.pop();
//             }
//         }
//         else
//         {
//             cout << zero << " ";
//         }
//     }

//     return 0;
// }
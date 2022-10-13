// #include <bits/stdc++.h>
// using namespace std;
// THIS QUESTION IS SIMILAR TO NEXT GREATER ELEMENT QUESTION
// HERE THE CONDITION JUST WOULD BE OPPOSITE AS THAT IN THE NEXT GREATER ELEMENT QUESTION
// TIME COMPLEXITY: O(N)
// SPACE COMPLEXITY: O(N)
// DRAWBACK: HERE THE ELEMENTS WOULD NOT APPEAR IN THE SAME ORDER AS THE INPUT SO IF WE WANT THE ELEMENTS IN THE SAME ORDER WE WOULD USE UNORDERED_MAP STL
// void nextSmaller(int arr[], int n)
// {
//     int temp;
//     stack<int> s;
//     for (int i = 0; i < n; i++)
//     {
//         while ((!s.empty()) && (arr[i] < s.top()))
//         {
//             temp = s.top();
//             s.pop();
//             cout << temp << "-->" << arr[i] << endl;
//         }
//         s.push(arr[i]);
//     }
//     while (!s.empty())
//     {
//         temp = s.top();
//         cout << temp << "--> -1"<<endl;
//         s.pop();
//     }
// }
// int main()
// {
//     int arr[] = {4, 8, 5, 2, 25};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     nextSmaller(arr, n);
//     return 0;
// }

// Elements will appear in the same output as the input
#include <bits/stdc++.h>
using namespace std;

void nextMin(int arr[], int n)
{
    int temp;
    stack<int> s;
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        while ((!s.empty()) && (arr[i] < s.top()))
        {
            int temp = s.top();
            s.pop();
            // cout << temp << "-->" << arr[i] << endl;
            m[temp] = arr[i];
        }
        s.push(arr[i]);
    }
    while (!s.empty())
    {
        temp = s.top();
        s.pop();
        // cout << temp << "--> -1" << endl;
        m[temp] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "-->" << m[arr[i]] << endl;
    }
}
int main()
{
    int arr[] = {4, 8, 5, 2, 25};
    int n = sizeof(arr) / sizeof(arr[0]);
    nextMin(arr, n);
    return 0;
}
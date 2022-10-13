#include <bits/stdc++.h>
using namespace std;

// NOTE: when I had checked this question by clicking on the given link by love babbar sheet it had opened me a different question
// so I am gonna solve both of the questions

// Question: to check whether each element of the array is a palindrome or not
// approach1:
// time complexity: O(N^2)
// space complexity: O(1)
bool isPalindrome(int N)
{
    // this is a way to convert a integer to a string
    string str;
    str = to_string(N);

    for (int i = 0; i < str.size() / 2; i++)
    {
        if (str[i] != str[str.size() - 1 - i])
        {
            return false;
        }
    }
    return true;
}

bool palindromicArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (!isPalindrome(a[i]))
        {
            return false;
        }
    }
    return true;
}

// approach2:
// time complexity: O(N^2)
// space complexityy: O(1)
bool plandromicArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        int temp = n;
        int ans = 0;
        while (temp > 0)
        {
            //remember the formula
            ans = ans * 10 + temp % 10;
            temp = temp / 10;
        }
        if (ans != temp)
        {
            return false;
        }
    }
    return true;
}

// question 2:
// minimum number of operations to make an array a palindrome you could only sum two adjacent elements
// time complexity: O(N)
// space complexity: O(1)
// iterative approach
// int minimumOperations(int *a, int n)
// {
//     int i = 0;
//     int j = n - 1;
//     int count = 0;
//     while (i != j)
//     {
//         if (a[i] == a[j])
//         {
//             i++;
//             j--;
//         }
//         else if (a[i] > a[j])
//         {
//             a[j - 1] = a[j - 1] + a[j];
//             count++;
//             j--;
//         }
//         else
//         {
//             a[i + 1] = a[i] + a[i + 1];
//             count++;
//             i++;
//         }
//     }
//     return count;
// }

// time complexity: O(N)
// space complexity: O(1)
// recursive approach
int minimumOperations(int *a, int n, int i, int j)
{
    if (i == j)
    {
        return 0;
    }

    if (i < j)
    {
        if (a[i] == a[j])
        {
            return minimumOperations(a, n, i + 1, j - 1);
        }
        else if (a[i] < a[j])
        {
            a[i + 1] = a[i] + a[i + 1];
            return minimumOperations(a, n, i + 1, j) + 1;
        }
        else
        {
            a[j - 1] = a[j - 1] + a[j];
            return minimumOperations(a, n, i, j - 1) + 1;
        }
    }
    return 0;
}
int main()
{
    int a[] = {1, 4, 5, 1};
    int n = sizeof(a) / sizeof(int);
    // if (palindromicArray(a, n))
    // {
    //     cout << "yes";
    // }
    // else
    // {
    //     cout << "no";
    // }

    cout << minimumOperations(a, n, 0, n-1);
    return 0;
}

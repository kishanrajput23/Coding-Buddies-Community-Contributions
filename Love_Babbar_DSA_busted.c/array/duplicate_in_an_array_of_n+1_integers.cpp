#include <bits/stdc++.h>
using namespace std;
// Question: Given an array of integers nums containing n+1 integers where each integer is in the range [1, n]
// inclusive.******** Here n is the index of the last element
// There is only one repeated number in nums , return this repeated mumber

// time complexity: O(N**2)
// space  complexity: O(1)
// int repeatedNumber(int *arr, int size)
// {

//     int element;
//     for (int i = 0; i < size; i++)
//     {
//         for (int j = i + 1; j < size; j++)
//         {
//             /* code */
//             if (arr[i] == arr[j])
//             {
//                 element = arr[i];
//             }
//         }
//     }
//     return element;
// }

// time complexity: o(N)
// space complexity: O(N)
// void duplicate(int *a, int n)
// {
//     int frequency[n] = {0};
//     for (int i = 0; i < n; i++)
//     {

//         if (frequency[a[i]] == 0)
//         {
//             frequency[a[i]] = 1;
//         }
//         else// if (frequency[a[i]] == 1)
//         {
//             cout << a[i] << endl;
//             return;
//         }
//     }
// }

// this is the most efficient approach to solve this problem and you will not find it any where I have seen it on 'take U forward ' you tube channel.
// approach:
// use hare and tortoise algorithm
// and find the starting of the loop just as similar to the linked list but the special thing is that we will not use linked list as an extra space here but we will iterate in the same array
// look at the video for better understanding. 
// time complexity: O(N)
// space complexity: O(1)
int duplicateElement(int* a, int n){
    int slow = a[0];
    int fast = a[0];
    do
    {
        slow = a[slow];
        fast = a[a[fast]];
    } while (slow != fast);
    fast = a[0];
    do
    {
        slow = a[slow];
        fast = a[fast];
    } while (slow != fast);
    
    return slow;
}
int main()
{
    int arr[] = {1, 2, 3, 7, 4, 5, 7, 6};
    int size = sizeof(arr) / sizeof(int);
    // int a = repeatedNumber(arr, size);
   int a = duplicateElement(arr, size);
    printf("The repeated number is %d \n", a);
    return 0;
}
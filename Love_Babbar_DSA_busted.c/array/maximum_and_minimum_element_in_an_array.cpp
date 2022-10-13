// #include <bits/stdc++.h>
// // A normal approach to solve this problem
// // time complexity: O(N)
// // space complexity: O(1)
// // NOTE: If want to return more than one value in a function either use pointers or structures .
// // write a program to find the maximum and minimum element in an array with minimum number of the comparisons.

// struct pair
// {
//     int max;
//     int min;
// };

// // This approach contains number of comparisons:
// // worst case comparisons (1+ 2*(n-2)) : When array is in descending order
// // best case comparisons (1 + (n-2))  : When array is in ascending order.
// struct pair getminmax(int *arr, int size)
// {
//     struct pair minmax;
//     int i = 0;
//     if (size == 1)
//     {
//         minmax.max = arr[0];
//         minmax.min = arr[0];
//         return minmax;
//     }

//     if (arr[i] > arr[i + 1])
//     {
//         minmax.max = arr[i];
//         minmax.min = arr[i + 1];
//     }
//     else
//     {
//         minmax.max = arr[i + 1];
//         minmax.min = arr[i];
//     }

//     for (int i = 2; i < size; i++)
//     {
//         if (arr[i] > minmax.max)
//         {
//             minmax.max = arr[i];
//         }
//         if (arr[i] < minmax.min)
//         {
//             minmax.min = arr[i];
//         }
//     }
//     return minmax;
// }
// int main()
// {
//     int arr[] = {-1, 4, 6, 8, -5};
//     int size = sizeof(arr) / sizeof(int);
//     struct pair minmax = getminmax(arr, size);
//     printf("The smallest element of the array is %d \n", minmax.min);
//     printf("The Greatest element of the array is %d \n", minmax.max);

//     return 0;
// }

#include <bits/stdc++.h>
// The best approach to solve this problem
// time complexity: O(N)
// space complexity: O(1)
// NOTE: If want to return more than one value in a function either use pointers or structures .
// write a program to find the maximum and minimum element in an array with minimum number of the comparisons.

struct pair
{
    int max;
    int min;
};

// this is the best method to find the smallest and the biggest element in the array with minimum number of the comparisons. 
// time complexity: O(N)
// space complexity: O(1)
// Number of comparisons : 
// even: 1+ 3*(n-2)/2
// odd: 3*(n-1)/2
struct pair getminmax(int *arr, int n)
{
    struct pair minmax;
    int i = 0;
    if (n % 2 == 0)
    {
        if (arr[0] > arr[1])
        {
            minmax.max = arr[0];
            minmax.min = arr[1];
        }
        else
        {
            minmax.max = arr[1];
            minmax.min = arr[0];
        }
        i=2;
    }
    else
    {
        minmax.max = arr[0];
        minmax.min = arr[0];
        i=1;
    }

    while (i <= n - 2)
    {
        if (arr[i] > arr[i + 1])
        {
            if (arr[i] > minmax.max)
            {
                minmax.max = arr[i];
            }
            if (arr[i + 1] < minmax.min)
            {
                minmax.min = arr[i + 1];
            }
        }
        else
        {
            if (arr[i + 1] > minmax.max)
            {
                minmax.max = arr[i + 1];
            }
            if (arr[i] < minmax.min)
            {
                minmax.min = arr[i];
            }
        }
        i = i + 2;
    }
    return minmax;
}
int main()
{
    int arr[] = {-1, 4, 6, 8, -5};
    int size = sizeof(arr) / sizeof(int);
    struct pair minmax = getminmax(arr, size);
    printf("The smallest element of the array is %d \n", minmax.min);
    printf("The Greatest element of the array is %d \n", minmax.max);

    return 0;
}

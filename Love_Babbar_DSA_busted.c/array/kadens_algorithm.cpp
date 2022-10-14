
// *** This is not Kadens algorithm ****
// This algorithm runs in O(n**3) big O of n cube.
// space algorithm: O(1)
// So we sholuld think of a better approach
// #include <stdio.h>
// #include <limits.h>
// int maxSubarray(int *arr, int size)
// {
//     int max = INT_MIN;
//     int cursum = 0;
//     for (int i = 0; i < size; i++)
//     {
//         for (int j = i; j < size; j++)
//         {
//             // int cursum=0;
//             for (int k = i; k <= j; k++)
//             {
//                 cursum += arr[k];
//             }
//             if (cursum > max)
//             {
//                 max = cursum;
//             }
//             cursum = 0;
//         }
//     }
//     return max;
// }
// int main()
// {
//     int arr[] = {1, 4, -2};
//     int size = 3;
//     int a = maxSubarray(arr, size);
//     printf("The value of max subarray is %d \n", a);
//     return 0;
// }

// This is a modified version of the above algorithm
// *** This is also not Kaden's algorithm ****
// This algorithm runs in O(n**2) big O of n square
// space complexity: O(N )
// #include <stdio.h>
// #include <stdlib.h>
// #include <limits.h>

// int maxSubArray(int *arr, int n)
// {
//     int cursum = 0;
//     int max = INT_MIN;
//     int *sum = (int *)malloc(n * sizeof(int));
//     sum[0] = arr[0];
//     for (int i = 1; i < n; i++)
//     {
//         sum[i] = sum[i - 1] + arr[i];
//     }
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i; j < n; j++)
//         {
//             cursum = sum[j] - sum[i] + arr[i];

//             if (cursum > max)
//             {
//                 max = cursum;
//             }
//             cursum = 0;
//         }
//     }
//     return max;
// }
// int main()
// {
//     int arr[] = {1, 4, -2};
//     int size = 3;
//     int a = maxSubArray(arr, size);
//     printf("The value of max subarray is %d \n", a);
//     return 0;
// }


// time complexity: O(N^2)
// sapce complexity: O(1)
// int maxsubarray(int *a, int n)
// {
//     int finalmax = INT_MIN;
//     for (int i = 0; i < n; i++)
//     {
//         int currsum = a[i];
//         for (int j = i+1; j < n; j++)
//         {
//             finalmax = max(finalmax, currsum);
//             currsum += a[j];
//         }
//         finalmax = max(finalmax, currsum);
//     }
//     return finalmax;
// }


// **** This is Kaden's Algorithm******
// This runs in Time Complexity O(n)
// space complexity: O(1)
#include <stdio.h>
#include <limits.h>
int Kadens_Algo_Max_SubArray(int *arr, int n)
{
    int max = INT_MIN;
    int cursum = 0;
    for (int i = 0; i < n; i++)
    {
        cursum += arr[i];
        if (cursum > max)
        {
            max = cursum;
        }
        if (cursum < 0)
        {
            cursum = 0;
        }
    }
    return max;
}
int main()
{
    int arr[] = {2, -1, -4, 10, -7, -5, 15};
    int size = sizeof(arr) / sizeof(int);
    int a = Kadens_Algo_Max_SubArray(arr, size);
    printf("The sum of largest contiguous subarray is %d \n", a);
    return 0;
}

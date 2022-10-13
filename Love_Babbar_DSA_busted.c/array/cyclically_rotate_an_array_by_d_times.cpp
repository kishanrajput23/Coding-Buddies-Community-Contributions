#include <stdio.h>
#include <stdlib.h>
void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void reverseArray(int *a, int i, int j)
{
    int li = i;
    int ri = j;

    while (li < ri)
    {
        int temp = a[li];
        a[li] = a[ri];
        a[ri] = temp;
        li++;
        ri--;
    }
}

// This is not the most efficient approach to solve this problem .
// Time complexity of this algo is : O(n*d)
// space complexity: O(1)
// void cyclically_rotate_an_array_by_d_times(int *a, int n, int d)
// {
//     for (int j = 0; j < d; j++)
//     {
//         int temp = a[n - 1];
//         for (int i = (n - 2); i >= 0; i--)
//         {
//             a[i + 1] = a[i];
//         }
//         a[0] = temp;
//     }
// }

// This is the most efficient approach to solve this problem.
// time complexity: O(N)
// space complexity: O(1)
// This algorithm is not on geeks for geeks .
// see the video of popcoding and you will able to understand the algorithm .
// Algorithm:
// 1. reverse the first part of the array.
// 2. reverse the second part of the array.
// 3. then reverse the whole array.
void cyclically_rotate_an_array_by_d_times(int *a, int n, int d)
{
    d = (d % n);
    reverseArray(a, 0, (n - d - 1));
    // printArray(a, n);
    reverseArray(a, (n - d), (n - 1));
    // printArray(a, n);
    reverseArray(a, 0, (n - 1));
    // printArray(a, n);
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(int);

    cyclically_rotate_an_array_by_d_times(arr, size, 101);
    printArray(arr, size);

    return 0;
}
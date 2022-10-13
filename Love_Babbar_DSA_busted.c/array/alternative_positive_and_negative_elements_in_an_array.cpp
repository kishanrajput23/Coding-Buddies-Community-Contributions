#include <stdio.h>
#include <stdlib.h>

// Question: Given an array of positive and negative numbers , arrange them in an alternate fashion such that every positive number is followed by negative and vice-versa maintaining the order of appearance . Number of positive and negative numbers need not  be equal . If there are more positive numbers they appear at the end of the array, they too appear in the  end of the array.

// some important things about this question.

// for arranging the elements in positive and negative order with maintaining order
// approach1: time complexity: O(N)
//   space complexity: O(N)

//approach 2: time compelxity: O(N**2)
//            space compelxity: O(1)

// for arrainging the elements in positive and negative order without maintaining the order

// the above two approaches can be used.

// approach : time complextiy: O(N)
//            space complexity: O(1)

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// This appraoch is made by me and the
// order will be maintained
// Time Complexity: O(n)
// Space Complexity: O(n )
// algorithm:
// create two arrays one with positive elements and other with negative elements .
// then put all the elements of the array into the original array alternatively  .
// void rearrange_positive_and_negative_alternatively(int *arr, int n)
// {
//     int a = 0, b = 0;
//     int i = 0, j = 0, k = 0;
//     for (i = 0; i < n; i++)
//     {
//         if (arr[i] >= 0)
//         {
//             a++;
//         }
//         else
//         {
//             b++;
//         }
//     }
//     int *ptr1 = (int *)malloc(a * sizeof(int));
//     int *ptr2 = (int *)malloc(b * sizeof(int));

//     for (i = 0; i < n; i++)
//     {
//         if (arr[i] >= 0)
//         {
//             ptr1[j] = arr[i];
//             j++;
//         }
//         else
//         {
//             ptr2[k] = arr[i];
//             k++;
//         }
//     }

//     j = 0;
//     k = 0;

//     for (int i = 0; i < n; i++)
//     {
//         if (j == a)
//         {
//             arr[i] = ptr2[k];
//             k++;
//             continue;
//         }
//         if (k == b)
//         {
//             arr[i] = ptr1[j];
//             j++;
//             continue;
//         }
//         if ((i % 2) == 0)
//         {
//             arr[i] = ptr2[k];
//             k++;
//         }
//         else
//         {
//             arr[i] = ptr1[j];
//             j++;
//         }
//     }
// }


// time complexity: O(N)
// space complexity: O(1)
// order will not be maintained
// algo:
// move all negative to one side and positive to one side.
// swap elements at odd positions with the positive elements . 
void swap(int *a, int *b)
{
    int temp = (*a);
    (*a) = (*b);
    (*b) = temp;
}

void segregate_positive_and_negative_elements(int a[], int n)
{
    int low = 0;
    // int mid; // we could use mid but there is no need of using it.
    int high = n - 1;

    while (low < high)
    {
        if (a[low] <= 0)
        {
            low++;
        }
        if (a[low] > 0)
        {
            swap(&a[low], &a[high]);
            high--;
        }
    }
}

void rearrange(int *a, int n)
{
    segregate_positive_and_negative_elements(a, n);
    int i = 1;
    int j = 0;
    for (int k = 0; k < n; k++)
    {
        if (a[k] > 0)
        {
            j = k;
            break;
        }
    }

    while (i < j && j < n)
    {
        swap(&a[i], &a[j]);
        i = i + 2;
        j++;
    }
}
int main()
{
    int arr[] = {-2, -22, -14, 5, -6, 7};
    // int arr[] = {-5, -2, 5, 2, 4, 7, 1, 8,0, -8};
    // int arr[] = {-5, -2, 5, -8};
    int size = sizeof(arr) / sizeof(int);
    printArray(arr, size);
    // rearrange_positive_and_negative_alternatively(arr, size);
    rearrange(arr, size);
    printArray(arr, size);
    // printArray(arr, size);
    return 0;
}
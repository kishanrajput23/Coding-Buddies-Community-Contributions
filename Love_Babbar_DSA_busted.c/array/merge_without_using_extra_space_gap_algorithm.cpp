#include <bits/stdc++.h>
using namespace std;
// see the video of the take u forward for better understanding.
// Question: Given two sorted arrays and we need to merge them without using any extra space
// TIP: INTERVIEWER would never say that to merge two sorted arrays without using extra space . He will just say to merge them in least time complexitY:

// approach 1: create an auxillary array and store them in sorted way and then copy them back.
// time complexity: O(N+M)
// space compelxity: O(N+M)
// void mergeThem(int a[], int b[], int n, int m)
// {
//     int i = 0;
//     int j = 0;
//     int k = 0;
//     int c[n + m];
//     while (i < n && j < m)
//     {
//         if (a[i] < b[j])
//         {
//             c[k] = a[i];
//             k++;
//             i++;
//         }
//         else if (a[i] > b[j])
//         {
//             c[k] = b[j];
//             k++;
//             j++;
//         }
//         else
//         {
//             c[k] = a[i];
//             i++;
//             j++;
//             k++;
//         }
//     }
//     while (i < n)
//     {
//         c[k] = a[i];
//         k++;
//         i++;
//     }
//     while (j < m)
//     {
//         c[k] = b[j];
//         k++;
//         j++;
//     }

//     k = 0;
//     for (i = 0; i < n; i++)
//     {
//         a[i] = c[k];
//         k++;
//     }
//     for (j = 0; j < m; j++)
//     {
//         b[j] = c[k];
//         k++;
//     }
// }

// approach 2:
// intution: use a insertion sort idea to merge the array
// traverse through the first array and then if it is less than the first element of the second array so swap them and sort the second array.
// assuming the first array is always greater than the first array.
// time complexity: O(N*M)
// space complexity: O(1)
// void sortThem(int *b, int m)
// {
//     int key = b[0];
//     for (int j = 1; j < m; j++)
//     {
//         if (key > b[j])
//         {
//             b[j - 1] = b[j];
//         }
//         else
//         {
//             b[j - 1] = key;
//             break;
//         }
//     }
// }

void swap(int *a, int *b)
{
    int temp = (*a);
    (*a) = (*b);
    (*b) = temp;
}

// void mergeThem(int *a, int *b, int n, int m)
// {
//     for (int i = 0; i < n; i++)
//     {
//         if (a[i] > b[0])
//         {
//             swap(&a[i], &b[0]);
//             sortThem(b, m);
//         }
//     }
// }

// The best approach to solve this problem is to use gap algorithm or called as shell sort
// check again this by code on take u forward .
int nextGap(int gap)
{
    if (gap <= 1)
        return 0;
    return (gap / 2) + (gap % 2);
}
void mergeThem(int *a, int *b, int n, int m)
{

    // int gap = ceil(((n + m) / 2.0));
    // cout<<gap<<endl;
    int gap = nextGap(n + m);
    int i ;
    int j;

    while (gap >0)
    {
        i=0;
        while (i + gap < n)
        {
            if (a[i] > a[i + gap])
            {
                swap(&a[i], &a[i + gap]);
            }
            i++;
        }
        if (gap > n)
        {
            j = gap - n;
        }
        else
        {
            j = 0;
        }
        while (i < n && j < m)
        {
            if (a[i] > b[j])
            {
                swap(&a[i], &b[j]);
            }
            i++;
            j++;
        }

        if (j < m)
        {
            j = 0;
            while (j + gap < m)
            {
                if (b[j] > b[j + gap])
                {
                    swap(&b[j], &b[j + gap]);
                }
                j++;
            }
        }
        // gap = ceil(gap / 2.0);
        // cout<<gap<<endl;
        gap = nextGap(gap);
    }
}

void merge(int *arr1, int *arr2, int n, int m)
{
    int i, j, gap = n + m;
    for (gap = nextGap(gap);
         gap > 0; gap = nextGap(gap))
    {
        cout<<gap<<endl;
        // comparing elements in the first array.
        for (i = 0; i + gap < n; i++)
            if (arr1[i] > arr1[i + gap])
                swap(arr1[i], arr1[i + gap]);

        // comparing elements in both arrays.
        for (j = gap > n ? gap - n : 0;
             i < n && j < m;
             i++, j++)
            if (arr1[i] > arr2[j])
                swap(arr1[i], arr2[j]);

        if (j < m)
        {
            // comparing elements in the second array.
            for (j = 0; j + gap < m; j++)
                if (arr2[j] > arr2[j + gap])
                    swap(arr2[j], arr2[j + gap]);
        }
    }
}
int main()
{
    // int a = 6;
    // int b = 5;
    // // float c= (a+b)/2;
    // int c= ceil((a+b)/2.0);
    // cout<<c<<endl;
    int arr2[] = {1, 4, 9, 12, 34, 78};
    int arr1[] = {2, 3,3,4, 56};
    int n = sizeof(arr1) / sizeof(int);
    int m = sizeof(arr2) / sizeof(int);
    // merge_without_using_extra_space(arr1, arr2, n, m);

    // merge(arr1, arr2, n, m);
    mergeThem(arr1, arr2, n, m);
    for (int i = 0; i < n; i++)
    {
        cout << arr1[i] << " ";
    }
    // cout << endl;
    for (int j = 0; j < m; j++)
    {
        cout << arr2[j] << " ";
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
// // Question:>> Write a function inversion count which tells how far or near is an array to be sorted
// // This is a simple approach
// The time complexity of the function is : O(n*n )
// int inversion_count(int *arr, int n)
// {
//     int count = 0;
//     for (int i = 0; i < n; i++)
//     {

//         {
//             for (int j = i + 1; j < n; j++)
//             {
//                 if (arr[i] > arr[j])
//                 {
//                     count++;
//                 }
//             }
//             /* code */
//         }
//     }
//     return count;
// }


// approach 2: using merge sort
// worst case time complexity: O(Nlog(N))
// space complexity: O(N)
// see video of apna college for better understanding . 
void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int merge(int a[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;
    int b[100];
    int inv_count = 0;
    while (i <= mid && j <= high)
    {
        if (a[i] <= a[j])
        {
            b[k] = a[i];
            k++;
            i++;
        }
        else
        {
            b[k] = a[j];
            k++;
            j++;
            // this is the most important point to undeerstand 
            // as elements are in ascending order so if a[i]>a[j], so all the elements from the right of a[i] would be greater than the a[j]
            inv_count = inv_count + (mid - i + 1);
        }
    }

    while (i <= mid)
    {
        b[k] = a[i];
        k++;
        i++;
    }

    while (j <= high)
    {
        b[k] = a[j];
        j++;
        k++;
    }

    for (int i = 0; i <= high; i++)
    {
        a[i] = b[i];
    }
    return inv_count;
}

int mergeSort(int a[], int low, int high)
{
    int inv_count = 0;
    if (low < high)
    {
        int mid = (low + high) / 2;
        inv_count += mergeSort(a, low, mid);
        inv_count += mergeSort(a, mid + 1, high);
        inv_count += merge(a, low, mid, high);
    }
    return inv_count;
}
int main()
{
    int a[] = {3, 1, 2};
    int n = sizeof(a) / sizeof(int);
    // display(a, n);
    // mergeSort(a, 0, n - 1);
    // display(a, n);
    cout << mergeSort(a, 0, n - 1) << endl;
    return 0;
}
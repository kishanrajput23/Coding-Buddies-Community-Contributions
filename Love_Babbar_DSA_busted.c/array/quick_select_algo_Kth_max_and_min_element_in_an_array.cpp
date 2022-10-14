#include <bits/stdc++.h>
// QUICK SELECT ALGORITHM
using namespace std;
// Find the kth maximum and kth minimum element of an array
// approach 1:
// sort the array using merge sort and return the arr[k-1] for minimum and similarly check for minimum
// time complexit: O(Nlog(n))
// space complexity: O(N)

// approach 2:
// using a max heap or a min heap but i have not done heap till now so I would check it later.
// I have done this in heap topic now

// approach 3:
// quick-select algorithm:
// average case time complexity: O(N)
// worst case time complexity: O(N**2)

// I have written 3rd approach in it which is the best approach called as 'quick Select algorithm'

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swap(int *a, int *b)
{
    int temp = (*a);
    (*a) = (*b);
    (*b) = temp;
}

int partition(int a[], int low, int high)
{
    int pivot = a[low];
    int i = low + 1;
    int j = high;
    // why do while loop?
    // because if the size of the array is 2 so then we will face the issue
    // e.g. 1,2 --> array size 2
    //     1(low)    2(high)(i)(j)
    // if we would use only while loop then it would not go inside the loop and we would swap a[low] and a[j] which would be wrong .
    // but now if we use do while loop then it needs to run one time so our indexes would look like
    //     1(low)(j)  2(high)(i)
    // so now if we swap a[low] and a[j] then it would be perfectly fine
    do
    {
        while (pivot >= a[i])
        {
            i++;
        }

        while (pivot < a[j])
        {
            j--;
        }

        if (i < j)
        {
            swap(&a[i], &a[j]);
        }

    } while (i < j);

    swap(&a[low], &a[j]);
    return j;
}

void quickSelectForKthMinimum(int a[], int low, int high, int k)
{
    if(low == high){
        cout<<a[k-1]<<endl;
        return;
    }
    if (low < high) // this conditon is to terminate the recursion low == high if the length of the array would be one'1'.
    {
        int partitionIndex = partition(a, low, high);
        if (partitionIndex < (k - 1))
        {
            quickSelectForKthMinimum(a, partitionIndex + 1, high, k); // this would sort right subarray.
        }
        else if (partitionIndex > (k - 1))
        {
            quickSelectForKthMinimum(a, low, partitionIndex - 1, k); // this would sort left subarray
        }
        else{
            cout<<a[k-1]<<endl;
            return;
        }
    }
}

void quickSelectForKthLargest(int a[], int low, int high, int k, int n)
{
    if(low == high){
        cout<<a[n-k]<<endl;
        return;
    }
    if (low < high) // this conditon is to terminate the recursion low == high if the length of the array would be one'1'.
    {
        int partitionIndex = partition(a, low, high);
        if (partitionIndex < (n-k))
        {
            quickSelectForKthLargest(a, partitionIndex + 1, high, k, n); // this would sort right subarray.
        }
        else if (partitionIndex > (n-k))
        {
            quickSelectForKthLargest(a, low, partitionIndex - 1, k, n); // this would sort left subarray
        }
        else{
            cout<<a[n-k]<<endl;
            return;
        }
    }
}

int main()
{
    int a[]= {1, 4, 3, 2, 5, 7};
    int n = sizeof(a)/sizeof(int);
    int k =5;
    cout<<"The "<<k<<"th "<<"largest element is ";
    quickSelectForKthLargest(a, 0, n-1, k, n);
    // cout<<endl;
    cout<<"The "<<k<<"th "<<"minimum element is ";
    quickSelectForKthMinimum(a, 0, n-1, k);
    return 0;
}
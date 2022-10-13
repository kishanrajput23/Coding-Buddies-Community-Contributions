#include <bits/stdc++.h>
using namespace std;

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// This is the simplest method to sort the array of 0, 1, 2 without using any sorting algo.
// time complexity: O(N)
// space commplexity: O(1)

// Disadvantages of using this algo:
// 1. we need to traverse the array more than one time.
// 2. we cannot use this algorithm if it is a class or structure e.g.: a structure of branches: 0--> CSE, 1--> ECE , 2--> ME

// So the better alternative is to use DNF sort
void sortArray(int a[], int n)
{
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            count0++;
        }
        else if (a[i] == 1)
        {
            count1++;
        }
        else
        {
            count2++;
        }
    }

    while (count0--)
    {
        a[j] = 0;
        j++;
    }
    while (count1--)
    {
        a[j] = 1;
        j++;
    }
    while (count2--)
    {
        a[j] = 2;
        j++;
    }
}

void swap(int *a, int *b)
{
    int temp = (*a);
    (*a) = (*b);
    (*b) = temp;
}

// dnf sort is the best approach to solve this problem
// time complexity: O(N)
// space complexity: O(1)
void dnfSort(int a[], int n)
{
    int low = 0;
    int mid = 0;
    int high = n - 1;

    while (mid <= high)
    {
        if (a[mid] == 0)
        {
            swap(&a[mid], &a[low]);
            mid++;
            low++;
        }
        else if (a[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(&a[mid], &a[high]);
            high--;
        }
    }
}
int main()
{
    int a[] = {0, 0, 1, 1, 0, 2, 1, 0};
    int n = sizeof(a) / sizeof(int);
    printArray(a, n);
    // sortArray(a, n);
    dnfSort(a, n);
    printArray(a, n);
    return 0;
}
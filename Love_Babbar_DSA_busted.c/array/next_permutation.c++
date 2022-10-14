#include <bits/stdc++.h>
using namespace std;
// Question:-->Next Permutation. Given an array of integers find the lexicographically greater permutation of it. For example: 1, 2, 4, 3 to 1, 3 , 2, 4
// see the 'tech dose ' you tube channel for best understanding code is also from there 
// The time complexity of this problem is : O(nlog(n))
// sapce complexity: O(1)


void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void reverseArray(int *arr, int size)
{
    int temp;
    for (int i = 0; i < size / 2; i++)
    {
        temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

void next_permutation(int *a, int n)
{
    if (n == 1)
    {
        return;
    }
    int i = 0;
    int lastInc = -1; // this stores the index of last ascending order peak
    while (i <= (n - 2))
    {
        if (a[i] < a[i + 1])
        {
            lastInc = i + 1;
        }
        i++;
    }
    // if array is in descending order
    if (lastInc == -1)
    {
        reverseArray(a, n);
        return;
    }

    int index = lastInc;
    for (i = lastInc + 1; i < n; i++)
    {
        if (a[i] > a[lastInc - 1] && a[i] < a[lastInc])
        {
            index = i;
        }
    }

    swap(a[lastInc - 1], a[index]);
    sort(a + lastInc, a + n);
}
int main()
{
    // int arr[] = {1, 2, 4, 3};
    int n = 6;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int size = sizeof(arr) / sizeof(int);
    // printArray(arr, size);
    next_permutation(arr, size);
    // next_permutation(arr, size);
    printArray(arr, size);
    return 0;
}
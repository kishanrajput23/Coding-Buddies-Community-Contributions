#include <bits/stdc++.h>
using namespace std;

// approach 
// simply build a max heap provided a random array (min heap)
// time complexity: O(n)
// space complexity: O(N)
void maxHeapify(int *arr, int n, int i)
{
    int lci = (2 * i) + 1;
    int rci = (2 * i) + 2;
    int largest = i;
    if (lci < n and arr[largest] < arr[lci])
    {
        largest = lci;
    }
    if (rci < n and arr[largest] < arr[rci])
    {
        largest = rci;
    }

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        maxHeapify(arr, n, largest);
    }
}

void minHeapToMaxHeap(int *arr, int n)
{
    int indx = (n - 2) / 2;
    for (int i = indx; i >= 0; i--)
    {
        maxHeapify(arr, n, i);
    }
}

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {5, 10, 20, 13, 17, 22, 24};
    int n = sizeof(arr) / sizeof(int);
    minHeapToMaxHeap(arr, n);
    printArray(arr, n);
    return 0;
}

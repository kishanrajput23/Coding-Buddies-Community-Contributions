#include <bits/stdc++.h>
using namespace std;

// Quoestion
// build a minHeap/maxHeap from the given random array
// time complexity:O(N) why O(N) check the notes 
// space complexity: O(1) ignoring recursive stack
int parent(int i)
{
    return (i - 1) / 2;
}

int leftChild(int i)
{
    return (2 * i + 1);
}

int rightChild(int i)
{
    return (2 * i + 2);
}
void minHeapify(int *arr, int n, int i)
{
    int lci = leftChild(i);
    int rci = rightChild(i);
    int smallest = i;

    if (lci < n && arr[smallest] > arr[lci])
    {
        smallest = lci;
    }
    if (rci < n && arr[smallest] > arr[rci])
    {
        smallest = rci;
    }

    if (smallest != i)
    {
        swap(arr[smallest], arr[i]);
        minHeapify(arr, n, smallest);
    }
}
void buildHeap(int *arr, int n)
{
    int lindx = parent(n - 1);
    for (int i = lindx; i >= 0; i--)
    {
        minHeapify(arr, n, i);
    }
}

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
int main()
{
    int arr[] = {4, 7, 9, 1, 3, 6, 12};
    int n = 7;
    printArray(arr, n);
    buildHeap(arr, n);
    printArray(arr, n);
    return 0;
}
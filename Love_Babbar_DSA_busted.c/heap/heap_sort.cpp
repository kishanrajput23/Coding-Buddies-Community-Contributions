#include <bits/stdc++.h>
using namespace std;

//Question
// sort using heap sort 
// we will use min heap to sort the elements in descending order and , 
// we will use max heap to sor the elements in ascending order 
// I have used max heap here 
// time complexity: O(N*(Log(N)))
// space complexity: O(1) ignoring recursive stack . 
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
void maxHeapify(int *arr, int &n, int i)
{
    int lci = leftChild(i);
    int rci = rightChild(i);
    int f = 0;
    int largest = i;
    // cout<<n<<" ";
    if (lci < n && arr[largest] < arr[lci])
    {
        largest = lci;
    }
    if (rci < n && arr[largest] < arr[rci])
    {
        largest = rci;
    }

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        maxHeapify(arr, n, largest);
    }
}
void buildHeap(int *arr, int n)
{
    int lindx = parent(n - 1);
    for (int i = lindx; i >= 0; i--)
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
    cout << "\n";
}

void heapSort(int *arr, int &n)
{
    buildHeap(arr, n);
    int size = n;
    int maxindx = 0;
    for (int i = size-1; i>=1; i--)
    {
        swap(arr[0], arr[n - 1]);
        // cout<<n<<" ";
        n--;
        maxHeapify(arr, n, maxindx);
    }
    n = size;
    // cout<<endl;
}

int main()
{
    int arr[] = {4, 7, 9, 1, 3, 6, 12};
    int n = 7;
    printArray(arr, n);
    heapSort(arr, n);
    printArray(arr, n);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

// Quoestion: merge two binary max heap
// approach
// copy all the elements to the separate array of size m+n 
// and then apply build heap function for it 
// time complexity: O(N+ M + N+M) === O(N+M)
// space complexity: O(N+M)
int parent(int i)
{
    return ((i - 1) / 2);
}

int left(int i)
{
    return (2 * i + 1);
}

int right(int i)
{
    return (2 * i + 2);
}
void heapify(int *res, int indx, int size)
{
    if (indx >= size)
        return;
    int lci = left(indx);
    int rci = right(indx);
    int largest = indx;

    if (lci < size && res[largest] < res[lci])
    {
        largest = lci;
    }
    if (rci < size && res[largest] < res[rci])
    {
        largest = rci;
    }

    if (largest != indx)
    {
        swap(res[largest], res[indx]);
        heapify(res, largest, size);
    }
}
void buildHeap(int *res, int size)
{
    int indx = parent(size - 1);
    for (int i = indx; i >= 0; i--)
    {
        heapify(res, i, size);
    }
}
void mergeThem(int *a, int n, int *b, int m, int *res, int size)
{
    //    int res[n+m];
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        res[j] = a[i];
        j++;
    }
    for (int i = 0; i < m; i++)
    {
        res[j] = b[i];
        j++;
    }

    buildHeap(res, size);
    // return res;
}
int main()
{
    int a[] = {12, 7, 9};
    int n = sizeof(a) / sizeof(int);
    int b[] = {10, 5, 6, 2};
    int m = sizeof(b) / sizeof(int);
    int size = n + m;
    int res[size];
    mergeThem(a, n, b, m, res, size);
    for (int i = 0; i < size; i++)
    {
        cout << res[i] << " ";
    }

    return 0;
}
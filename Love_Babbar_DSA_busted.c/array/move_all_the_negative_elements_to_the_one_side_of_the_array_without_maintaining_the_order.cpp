#include <bits/stdc++.h>
using namespace std;
// Write a program to segregate positive and negative elements in an array negative at first and positive at end .

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

void swap(int *a, int *b)
{
    int temp = (*a);
    (*a) = (*b);
    (*b) = temp;
}

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// approach 1: to use quick sort partition method .
// time complexitY; O(N)
// space complexity: O(1)
// Choose the smallest positive element and then apply partition method of the quick sort .
// void segregate_positive_and_negative(int a[], int n)
// {
//     int p = 0;
//     int minindx = INT_MAX;
//     for (p = 0; p < n; p++)
//     {
//         if (a[p] > 0 && a[minindx] > a[p])
//         {
//             minindx = p;
//         }
//     }
//     swap(&a[minindx], &a[0]);
//     int pivot = a[0];
//     int i = 1;
//     int j = n - 1;
//     do
//     {
//         while (a[i] <= pivot)
//         {
//             i++;
//         }
//         while (a[j] > pivot)
//         {
//             j--;
//         }

//         if (i < j)
//         {
//             swap(&a[i], &a[j]);
//         }

//     } while (i < j);

//     swap(&a[j], &a[0]);
// }

// use dnf sort to segregate them
// time complexity: O(N)
// space complexity: O(1)
void segregate_positive_and_negative_elements(int a[], int n)
{
    int low = 0;
    int mid; // we could use mid but there is no need of using it.
    int high = n - 1;

    while (low < high)
    {
        if (a[low] < 0)
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
int main()
{
    int a[] = {4, 3, -1, -3, 34, -1, 1, -1, -1, -1};
    int n = sizeof(a) / sizeof(n);
    printArray(a, n);
    // segregate_positive_and_negative(a, n);
    segregate_positive_and_negative_elements(a, n);
    printArray(a, n);
    return 0;
}
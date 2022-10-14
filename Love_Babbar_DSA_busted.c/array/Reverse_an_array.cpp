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

// Iterative way to reverse an array 
// Time complexity of the reverse array function is O(n)
// space complexity: O(1)
// void reverseArray(int *arr, int size)
// {
//     int temp;
//     for (int i = 0; i < size / 2; i++)
//     {
//         //swap them 
//         temp = arr[i];
//         arr[i] = arr[size - 1 - i];
//         arr[size - 1 - i] = temp;
//     }
// }

// recursive way to reverse an array 
// time complexity: O(N)
// space complexity: O(1)
void reverseArray(int *arr, int i, int size)
{
        if(i> ((size/2)-1)){
            return;
        }
        reverseArray(arr, i+1, size);
        int temp;
        temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    
}
int main()
{
    int arr[] = {2, 23, 4, 9, 5};
    int size = sizeof(arr) / sizeof(int);
    printArray(arr, size);
    // reverseArray(arr, size);
    reverseArray(arr, 0, size);
    printArray(arr, size);

    return 0;
}
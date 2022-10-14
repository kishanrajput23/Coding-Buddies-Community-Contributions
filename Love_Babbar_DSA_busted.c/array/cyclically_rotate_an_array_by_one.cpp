#include <stdio.h>
#include <stdlib.h>
void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Time complexity of this algo is : O(n)
// space complexity: O(1)
void cyclically_rotate_an_array_by_one(int *a, int n)
{
    int temp = a[n-1];
    for (int i = (n-2); i>=0; i--)
    {
        a[i+1]= a[i];
    }
    a[0]= temp;   
}
int main()
{
    int arr[] = {2, 1, 5, 4};
    int size = 4;
    printArray(arr, size);

    cyclically_rotate_an_array_by_one(arr, size);
    printArray(arr, size);
    return 0;
}
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

/*This  function has Time complexity O(4n) after the constant : O(n)*/
void sorting(int *arr, int size)
{
    int j = 0;
    int *ptr = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 0)
        {
            ptr[j] = 0;
            j++;
        }
    }
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 1)
        {
            ptr[j] = 1;
            j++;
        }
    }
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 2)
        {
            ptr[j] = 2;
            j++;
        }
    }

    for (int j = 0; j < size; j++)
    {
        arr[j] = ptr[j];
    }
}
int main()
{
    int arr[] = {2, 1, 0, 0, 1, 1, 0, 1, 2, 0, 1};
    int size = sizeof(arr) / sizeof(int);
    printArray(arr, size);
    sorting(arr, size);
    printArray(arr, size);
    return 0;
}
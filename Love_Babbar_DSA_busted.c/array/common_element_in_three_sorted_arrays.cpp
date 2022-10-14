#include <bits/stdc++.h>
using namespace std;
// This approach is made by me. This  is simplest to think as we only need to traverse the arrays and print the element when we find the common elements of all three. but it's the worst  when it comes to  efficiency of this algo as it's time complexity: is : O(n*n*n) big O of n cube

// Time Complexity: O(n cube )
// void  common_element(int* a1, int* a2, int* a3, int n1, int n2, int n3)
// {

//     int i, j, k;
//     for ( i = 0; i < n1; i++)
//     {
//         for ( j = 0; j < n2; j++)
//         {
//             for( k = 0; k < n3; k++)
//             {
//                 if (a1[i] == a2[j] && a2[j]== a3[k])
//                 {
//                     printf("%d ",a1[i] );
//                 }
//             }
//         }
//     }

// }

// This  is second approach to  print the common elements of three sorted  arrays . This is a netter approach then the first one as it has
// Time complexity : O(n1+n2+ n3 )
// Space ComplexityL: O(n1 )
// In this approach we have to fire two loops and an extra space . We could do this  in more efficient way  just by firing one loop with no extra space and that's how the magic begins
// void common_elements(int *a1, int *a2, int *a3, int n1, int n2, int n3)
// {
//     int i = 0, j = 0, k = 0;

//     int *ptr = (int *)malloc(n1 * sizeof(int));

//     while (i < n1 && j < n2)
//     {
//         if (a1[i] < a2[j])
//         {
//             i++;
//         }
//         else if (a1[i] > a2[j])
//         {
//             j++;
//         }
//         else
//         {
//             ptr[k] = a1[i];
//             i++;
//             j++;
//             k++;
//         }
//     }
//     k = 0;
//     int l = 0;
//     while (k < n1 && l < n3)
//     {
//         if (ptr[k] < a3[l])
//         {
//             k++;
//         }
//         else if (ptr[k] > a3[l])
//         {
//             l++;
//         }
//         else
//         {
//             printf("%d ", a3[l]);
//             k++;
//             l++;
//         }
//     }
// }

// This is the best approach to solve this problem as it  takes O(n1+n2+n3) without any extra space and in a single loop
// Time Complexity  : O(n1+n2+n3)
// Space complexity : O(1)
void common_elements(int *a1, int *a2, int *a3, int n1, int n2, int n3)
{
    //Initialize starting elements of  a1, a2, a3
    int i = 0;
    int j = 0;
    int k = 0;

    // Iterate through three arrays while  all arrays have elements
    while (i < n1 && j < n2 && k < n3)
    {
        // all the elements of three elements are equal
        if (a1[i] == a2[j] && a2[j] == a3[k])
        {
            printf("%d ", a1[i]);
            i++;
            j++;
            k++;
        }

        // x<y
        else if (a1[i] < a2[j])
        {
            i++;
        }

        // y<z
        else if (a2[j] < a3[k])
        {
            j++;
        }

        // loop will come here when x>y and y>z i.e. z is  the smallest element among three arrays
        else
        {
            k++;
        }
    }
}

void commonElements(int *a, int *b, int *c, int m, int n, int o)
{
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < m && j < n && k < o)
    {
        if (a[i] == b[j]  && b[j]== c[k])
        {
            cout << a[i] << " ";
            i++;
            j++;
            k++;
        }
        else if (a[i] < b[j] && a[i] < c[k])
        {
            i++;
        }
        else if (b[j] < a[i] && b[j] < c[k])
        {
            j++;
        }
        else if (c[k] < a[i] && c[k] < b[j])
        {
            k++;
        }
        else if (a[i] == b[j] && a[i] < c[k])
        {
            i++;
            j++;
        }
        else if (b[j] == c[k] && b[j] < a[i])
        {
            j++;
            k++;
        }
        else
        {
            i++;
            k++;
        }
    }
}
int main()
{
    int a1[] = {1, 2, 4, 5, 7, 9};
    int a2[] = {1, 3, 4, 7, 8};
    int a3[] = {2, 4, 7, 10};
    // int n1 = 4, n2 = 4, n3 = 4;
    int n1 = sizeof(a1) / sizeof(int);
    int n2 = sizeof(a2) / sizeof(int);
    int n3 = sizeof(a3) / sizeof(int);

    // common_elements(a1, a2, a3, n1, n2, n3);
    commonElements(a1, a2, a3, n1, n2, n3);
    return 0;
}
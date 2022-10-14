#include <bits/stdc++.h>
using namespace std;
// I will do this question later on as they are two very difficult questions 
// this time I need to start trees I will come back to it. 

int median_of_two_sorted_arrays(int *a1, int *a2, int n)
{
    int k = 0;
    int i = 0;
    int j = 0;
    while (k <= n)
    {
        if (a1[i] < a2[j])
        {
            if (k == (n  - 1))
            {
                int a = a1[i];
            }
            if(k== n){
                int b = a1[i];
            }


            
            i++;
            k++;
        }
        else{
            j++;
            k++;
        }
    }
}
int main()
{
    int a[] = {1, 4, 5, 1};
    int n = sizeof(a) / sizeof(int);
    // if (palindromicArray(a, n))
    // {
    //     cout << "yes";
    // }
    // else
    // {
    //     cout << "no";
    // }

    cout << minimumOperations(a, n, 0, n - 1);
    return 0;
}

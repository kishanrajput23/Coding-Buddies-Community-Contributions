#include <bits/stdc++.h>
using namespace std;

// approach 1: 
// sort the array
// time complexity: O(Nlog(N))
// space complextiy: O(1)

// approach2: 
// use dnf sort idea for partioning 
// time complexity: O(N)
// space complexity: O(1)
void threeWayPartition(int *arr, int n, int a, int b)
{
    int low =0;
    int mid =0;
    int high = n-1;
    while (mid<=high)
    {
        if(arr[mid]<a){
            swap(arr[mid], arr[low]);
            low++;
            mid++;
        }
        else if(arr[mid]>b){
            swap(arr[mid], arr[high]);
            high--;
        }
        else{
            mid++;
        }
    }
    
}

int main()
{
    int arr[] = {1, 2, 5, 7, 3, 8, 4, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    threeWayPartition(arr, n, 3, 8);

    cout << "Modified array \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

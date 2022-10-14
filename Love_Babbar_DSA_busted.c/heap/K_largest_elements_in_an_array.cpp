#include <bits/stdc++.h>
using namespace std;

//Question
// find the k largest elements in an array
// time complexity: O(k + (N-k-1)*log(K))
// spac complexity: O(K)
void kLargestElements(int* arr, int n,int k)
{
    priority_queue<int, vector<int> , greater<int> > q;
    for (int i = 0; i < k; i++)
    {
        q.push(arr[i]);
    }
    
    for (int i = k; i < n; i++)
    {
        if(q.top()<arr[i])        
        {
            q.pop();
            q.push(arr[i]);
        }
    }
    
    while (!q.empty())
    {
        cout<<q.top()<<" ";
        q.pop();
    }
    

}

int main()
{
    int arr[] = {4, 7, 9, 1, 3, 6, 12};
    int n = sizeof(arr)/sizeof(int);
    int k = 3;
    kLargestElements(arr, n, k);
    return 0;
}
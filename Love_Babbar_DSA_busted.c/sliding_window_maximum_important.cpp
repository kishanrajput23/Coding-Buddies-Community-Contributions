#include <bits/stdc++.h>
using namespace std;
// This is a very important question sliding window maximum
// write a program to print the maximum element in a window of size k  
// it is the most efficient approach to solve this problem 
// brute force approach : O(N*K)

// efficient approach: 
// use a dequeue data structure 
// 1. create a deque to store k elements. 
// 2. run a loop annd insert first k elements in the deque. before inserting the element, check if the element at the back of the queeue is smaller than the current element, if it is so remove the element from the  back of the queue, until all elements left in the queue are reater thann the current element, at the back of the dequeue. 
//3. Now, run a loop from k to end of the array. 
//4. Print the front element of the dequeue. 
// 5. 
// remove the element from the front of the queue if they are out of the current window. 
// 6. inert the next element in the DEque. Before inserting the element, check if the element at the back of the queue is smaller than the current element, if the is so remove the element from the bakcof the deque, until all elements left in the deque are greater than the current element. Then insert the current element, at the back of the deque. 
// 7. Print the maximum element of the last window. 

//  TIME COMPLEXITY: O(N)
// SPACE COMPLEXITY: O(K)

void printMaximumElementOfWindowSizeK(int arr[], int n, int k)
{
    deque<int> q;
    int i;
    for (i = 0; i < k; i++)
    {

        while ((!q.empty()) && (arr[i] >= arr[q.back()]))
        {
            q.pop_back();
        }
        q.push_back(i);
    }

    for (; i < n; i++)
    {
        cout << arr[q.front()] << " ";

        while ((!q.empty()) && (q.front() <= (i - k)))
        {
            q.pop_front();
        }

        while ((!q.empty()) && (arr[i] >= arr[q.back()]))
        {
            q.pop_back();
        }
        q.push_back(i);
    }
    cout<<arr[q.front()]<<" ";
}
int main()
{
    int arr[] = {12, 1, 78, 90, 57, 89, 56};
    int n = sizeof(arr) / sizeof(int);
    int k = 3;
    printMaximumElementOfWindowSizeK(arr, n, k);
}
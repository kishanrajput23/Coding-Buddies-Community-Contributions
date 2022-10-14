#include <bits/stdc++.h>
using namespace std;
// QUESTION

// A stack permutation is a permutation of objects in the given input queue which is done by transferring elements from input queue to the output queue with the help of a stack and the built-in push and pop functions.

// The well defined rules are:

// Only dequeue from the input queue.
// Use inbuilt push, pop functions in the single stack.
// Stack and input queue must be empty at the end.
// Only enqueue to the output queue.
// There are a huge number of permutations possible using a stack for a single input queue.
// Given two arrays, both of unique elements. One represents the input queue and the other represents the output queue. Our task is to check if the given output is possible through stack permutation.

// This algorithm is made by me and only by me. 
// time complexity: O(N)
// space complexity: O(1)

/// ALGORITHM;
// 1. always pop an element from the 'iq' and push that popped element into the stack 
// 2. then check if the top element of the stack is equal to the front element of the 'oq'
// 3. if equal then continue otherwise repeat the 1. step again
// 4. if equal then pop the element from the stack and also from the 'oq' until s.top()= oq.front()
// 5. at last if the stack is empty return 1
// 6 otherwise return 0
int stack_permutation(int ip[], int op[], int n)
{
    queue<int> iq;
    queue<int> oq;
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        iq.push(ip[i]);
    }

    for (int i = 0; i < n; i++)
    {
        oq.push(op[i]);
    }

    while (!iq.empty())
    {
        int val = iq.front();
        iq.pop();
        s.push(val);

        if (s.top() == oq.front())
        {
            while (s.top() == oq.front())
            {
                s.pop();
                oq.pop();
                if (s.empty())
                {
                    break;
                }
            }
        }
    }

    if (s.empty())
    {
        return 1;
    }
    return 0;
}

int main()
{

    int input[] = {1, 2, 3, 4};
    int output[] = {3, 2, 1, 4};
    int n = 3;

    if (stack_permutation(input, output, n))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NOT POSSIBLE" << endl;
    }
    return 0;
}
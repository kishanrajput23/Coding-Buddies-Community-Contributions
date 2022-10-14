#include <bits/stdc++.h>
using namespace std;

// Assuming stack contains distinct values
// approach: push the element into the queue
// then pop all the elements until the front element is that val 
// then push back all the elements and hence the push operation works

// approach  is made by me 
// push : O(N)
// pop: O(1)
class Stack
{
    int n;
    queue<int> q;

public:
    void stack()
    {
        n = 0;
    }

    void push(int val)
    {
        q.push(val);
        while (q.front() != val)
        {
            int a = q.front();
            q.pop();
            q.push(a);
        }
        n++;
    }

    int pop()
    {
        n--;
        int val = q.front();
        q.pop();
        return val;
    }
};

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Stack
{
    int N;
    deque<int> q;

public:
    Stack()
    {
        N = 0;
    }

    void push(int val)
    {
        N++;
        q.push_front(val);
    }

    int pop()
    {
        N--;
        int val = q.front();
        q.pop_front();
        return val;
    }

    int top()
    {
        return q.front();
    }

    int size()
    {
        return N;
    }
};

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    return 0;
}
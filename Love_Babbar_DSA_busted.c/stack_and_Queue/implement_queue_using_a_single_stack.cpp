#include <bits/stdc++.h>
using namespace std;

class Queue
{
    int n;
    stack<int> s;

public:
    Queue()
    {
        n = 0;
    }

    void push(int val)
    {
        n++;
        if (s.empty())
        {
            s.push(val);
            return;
        }
        int value = s.top();
        s.pop();
        push(val);
        s.push(value);
    }

    int pop(){
        n--;
        int var = s.top();
        s.pop();
        return var;
    }

    int front(){
        return s.top();
    }

    int size(){
        return n;
    }
};

int main()
{
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    return 0;
}
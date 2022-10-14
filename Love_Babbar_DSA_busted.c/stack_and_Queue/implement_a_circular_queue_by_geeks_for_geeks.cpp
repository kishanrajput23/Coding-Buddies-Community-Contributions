#include <bits/stdc++.h>
using namespace std;

class circularQueue
{
public:
    int size, f, r;
    int *arr;
    unsigned capacity;

    circularQueue(unsigned cap)
    {
        capacity = cap;
        f = 0;
        size = 0;
        r = (capacity - 1);
        arr = new int[capacity];
    }

    bool empty()
    {
        if (size == 0)
        {
            return true;
        }
        return false;
    }

    bool full()
    {
        if (size == capacity)
        {
            return true;
        }
        return false;
    }

    void enqueue(int val)
    {
        if (full())
        {
            cout << "Circular Queue overflow" << endl;
            return;
        }
        else
        {
            r = (r + 1) % capacity;
            arr[r] = val;
            size = size + 1;
        }
    }

    int dequeue()
    {
        if (empty())
        {
            cout << "Circular queue underflow" << endl;
            return -1;
        }
        else
        {
            int val = arr[f];
            f = ((f + 1) % size);
            size--;
            return val;
        }
    }
};
int main()
{
    circularQueue q(1000);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    return 0;
}
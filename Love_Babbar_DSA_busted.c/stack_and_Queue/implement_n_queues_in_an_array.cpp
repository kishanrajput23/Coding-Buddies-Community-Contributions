#include <bits/stdc++.h>
using namespace std;

class kQueues
{
    int *arr;
    int *front;
    int *rear;
    int *next;
    int n, k;
    int free;

public:
    kQueues(int k, int n);

    bool isFull(){ return (free == -1);}

    void enqueue(int item, int qn);

    int dequeue(int qn);

    bool isEmpty(int qn){ return (front[qn]== -1);}
};

kQueues::kQueues(int k1, int n1)
{
    k = k1;
    n = n1;
    arr = new int[n];
    next = new int[n];
    front = new int[k];
    rear = new int[k];

    for (int i = 0; i < k; i++)
    {
        front[i] = -1;
    }

    for (int i = 0; i < n - 1; i++)
    {
        next[i] = (i + 1);
    }

    next[n - 1] = -1;
    free=0;
}

void kQueues::enqueue(int item, int qn)
{
    if (isFull())
    {
        cout << "Queue Overflow" << endl;
        return;
    }
    else
    {
        int i = free;
        free = next[i];

        if (isEmpty(qn))
        {
            front[qn] = i;
        }
        else
        {
            next[rear[qn]] = i;
        }

        next[i] = -1;
        rear[qn] = i;
        arr[i] = item;
    }
}

int kQueues::dequeue(int qn)
{
    if (isEmpty(qn))
    {
        cout << "Queue underflow" << endl;
        return INT_MAX;
    }
    int i = front[qn];
    front[qn] = next[i];
    next[i] = free;
    free = i;
    return arr[i];
}
int main()
{
    int k= 3;
    int n= 5;
    kQueues q(k, n);
    q.enqueue(4, 0);
    q.enqueue(7, 0);
    q.enqueue(55, 0);
    q.enqueue(62, 2);
    // cout<<"hi"<<endl;
    cout<<q.dequeue(0)<<endl;
    
    return 0;
}
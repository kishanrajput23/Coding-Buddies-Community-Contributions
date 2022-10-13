#include <bits/stdc++.h>
using namespace std;

void queue_reverse(queue<int> &q)
{
    if (q.empty())
    {
        return;
    }
    int val = q.front();
    q.pop();
    queue_reverse(q);
    q.push(val);
}

void display(queue<int> &q)
{
    queue<int> qt = q;
    while (!qt.empty())
    {
        cout << qt.front() << " ";
        qt.pop();
    }
    cout << endl;
}
int main()
{
    queue<int> q;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        q.push(x);
    }

    queue_reverse(q);
    cout<<"The reversed Queue is : "<<endl;
    display(q); 
    return 0;
}
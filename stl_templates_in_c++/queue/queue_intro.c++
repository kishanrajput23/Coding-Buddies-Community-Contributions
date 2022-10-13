#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> q;
    q.push(2);
    q.push(5);
    q.push(6);
    while (!q.empty())
    {
        cout << q.front()<<" ";
        q.pop();
    }
    return 0;
}
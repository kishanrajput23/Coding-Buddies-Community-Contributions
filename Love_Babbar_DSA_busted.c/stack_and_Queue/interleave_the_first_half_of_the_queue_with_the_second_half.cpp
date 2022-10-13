#include <bits/stdc++.h>
using namespace std;

// Given a queue of integers of even length, rearrange the elements by interleaving the first half of the queue with the second half of the queue.

// Only a stack can be used as an auxiliary space.

// Examples:

// Input :  1 2 3 4
// Output : 1 3 2 4

// Input : 11 12 13 14 15 16 17 18 19 20
// Output : 11 16 12 17 13 18 14 19 15 20

// time complexity : o(N)
// space complexity: O(N)
bool isEven(int counter)
{
    if (counter % 2 == 0)
    {
        return true;
    }
    return false;
}

void reverse_queue(queue<int> &q)
{
    if (q.empty())
    {
        return;
    }
    int val = q.front();
    q.pop();
    reverse_queue(q);
    q.push(val);
}
void interleave(queue<int> &q, int n)
{
    reverse_queue(q);
    stack<int> s1;
    stack<int> s2;
    int count = 0;
    while (!q.empty())
    {
        int val = q.front();
        q.pop();
        if (count >= (n / 2))
        {
            s2.push(val);
        }
        else
        {
            s1.push(val);
        }
        count++;
    }

    int counter = 0;
    while (q.size() != n)
    {
        if (isEven(counter))
        {
            int temper = s2.top();
            s2.pop();
            q.push(temper);
        }
        else
        {
            int temp = s1.top();
            s1.pop();
            q.push(temp);
        }
        counter++;
    }
}

void display(queue<int> &q, int n)
{
    queue<int> qq = q;
    for (int i = 0; i < n; i++)
    {
        cout << qq.front() << " ";
        qq.pop();
    }
    cout << endl;
}

int main()
{
    queue<int> q;

    int n;
    cin >> n; // n should be even
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        q.push(x);
    }

    // display(q, n);
    interleave(q, n);
    display(q, n);
    return 0;
}
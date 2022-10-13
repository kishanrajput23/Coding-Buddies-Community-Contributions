#include <bits/stdc++.h>
using namespace std;
// This question is already done in stack and queues but I am still doing it again just for practice 
// time complexity: O(nLog(n) + n)== O(nlog(n))
// space complexity : O(n)
// we could also do this problem without using any extra space see the stack and queue for it just modified in the same array 
int main()
{
    vector<pair<int, int>> a;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int c;
        int b;
        cin >> c >> b;
        a.push_back({c, b});
    }
    sort(a.begin(), a.end());
    stack<pair<int, int>> s;
    s.push({a[0].first, a[0].second});
    for (int i = 1; i < n; i++)
    {
        if (s.top().second >= a[i].first)
        {
            s.top().second = max(s.top().second, a[i].second);
        }
        else
        {
            s.push({a[i].first, a[i].second});
        }
    }
    // reverseStack(s);
    while (!s.empty())
    {
        cout << "(" << s.top().first << "," << s.top().second << ")"
             << " ";
        s.pop();
    }

    return 0;
}
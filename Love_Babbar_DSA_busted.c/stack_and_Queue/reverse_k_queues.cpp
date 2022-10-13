#include <bits/stdc++.h>
using namespace std;

// time complexity: O(N)
// space complexity: O(n)
void reverse_k_items(queue<int> &q, int k)
{
    vector<int> a(k);
    for (int i = 0; i < k; i++)
    {
        a[i] = q.front();
        q.pop();
    }
    int val = a[k-1];
    for (int i = k - 1; i >= 0; i--)
    {
        q.push(a[i]);
    }
    while(q.front()!= val){
        int temp = q.front();
        q.pop();
        q.push(temp);
    }

}

void display(queue<int> &q)
{
    queue<int> qt = q;
    while (!qt.empty())
    {
        int a = qt.front();
        cout << a << " ";
        qt.pop();
    }
    cout<<endl;
}
int main()
{
    queue<int> q;
    int n;
    int k;
    cin>>n;
    cin >> k;

    for (int i = 0; i < n; i++)
    {
       int x;
       cin>>x;
       q.push(x);
    }
    
    reverse_k_items(q, k);
    display(q);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

void reverseArray(vector<int> &a)
{
    for (int i = 0; i < a.size() / 2; i++)
    {
        int temp = a[i];
        a[i] = a[a.size() - i - 1];
        a[a.size() - i - 1] = temp;
    }
}

// remember the approach . 
// time complexity: O(N)
// space complexity: O(1)
vector<int> factorialOfLargeNumber(int n)
{
    vector<int> a;
    a.push_back(1);

    for (int i = 2; i <= n; i++)
    {
        int c = 0;
        int j = 0;
        int s = a.size();
        while (s--)
        {
            int temp = a[j] * i + c;
            a[j] = temp % 10;
            c = temp / 10;
            j++;
        }

        while (c)
        {
            int temp = c % 10;
            a.push_back(temp);
            c = c / 10;
        }
    }

    reverseArray(a);
    return a;
}
int main()
{
    int n;
    cin >> n;
    vector<int> a = factorialOfLargeNumber(n);

    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i];
    }

    return 0;
}



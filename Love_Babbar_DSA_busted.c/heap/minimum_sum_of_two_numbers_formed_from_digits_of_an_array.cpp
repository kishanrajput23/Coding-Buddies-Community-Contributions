#include <bits/stdc++.h>
using namespace std;

string sumMin(int arr[], int n)
{
    sort(arr, arr + n);
    int f = 1;
    string s1;
    string s2;
    string res;
    for (int i = 0; i < n; i++)
    {
        if (f)
        {
            f = 0;

            s1 = s1 + to_string(arr[i]);
        }
        else
        {
            f = 1;
            s2 = s2 + to_string(arr[i]);
        }
    }

    // cout << s1 << " " << s2 << endl;
    int c = 0;
    int p = s1.size() - 1;
    int q = s2.size() - 1;
    while (p >= 0 || q >= 0)
    {
        int a, b;
        if (p >= 0)
        {
            char temp = s1[p];
            a = temp - '0';
            // cout << a << " ";
        }
        else
        {
            a = 0;
        }

        if (q >= 0)
        {
            char temp = s2[q];
            b = temp - '0';
            // cout << b << " ";
        }
        else
        {
            b = 0;
        }

        int temp = a + b + c;
        // cout << temp << endl;
        if (temp >= 10)
        {
            c = 1;
        }
        else
        {
            c = 0;
        }
        temp = temp % 10;
        string s = to_string(temp);
        res = res + s;
        p--;
        q--;
    }
    if (c)
    {
        res = res + to_string(c);
    }
    reverse(res.begin(), res.end());

    return res;
}
int main()
{
    int arr[] = {6, 5, 0, 9, 0, 0, 6, 1, 3, 8, 9, 3, 4, 4, 6, 0, 6, 6, 1, 8, 4, 9, 6, 3, 7, 8, 8, 2, 9};
    int n = sizeof(arr) / sizeof(int);
    string res = sumMin(arr,n);
    auto it = res.begin();

    cout<<count<<endl;
    cout << res;

    return 0;
}
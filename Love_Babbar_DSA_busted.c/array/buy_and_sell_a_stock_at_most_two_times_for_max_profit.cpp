#include <bits/stdc++.h>
using namespace std;

// maximum profit gained by buying and selling the stock atmost two times. 
// the approach is same as of to buy and sell a stock onlyy once. 
// just the difference is that we need to applly this approach after the first peak is achieved. 
// look at the  code for better understanding. 
// time complexity: O(N)
// space commplexity: O(1)
int sell_at_most_two_times(int *a, int n)
{
    int msf = a[0];
    bool flag = false;
    int rmax = INT_MIN;
    int i;
    for (i = 1; i < n; i++)
    {
        msf = min(a[i], msf);
        if (a[i - 1] < a[i])
        {
            flag = true;
            rmax = max(rmax, a[i] - msf);
        }
        else
        {
            if (flag)
            {
                break;
            }
            rmax = max(rmax, a[i] - msf);
        }
    }

    if(i==n){
        return rmax;
    }
    msf = a[i];
    int cmax = INT_MIN;
    for (int j = i; j < n; j++)
    {
        msf = min(a[j], msf);
        cmax = max(cmax, a[j] - msf);
    }

    
    return (rmax + cmax)<=0 ? 0: (rmax+cmax);
}
int main()
{
    int a[] = {90, 80, 70, 60, 50};
    int n = sizeof(a) / sizeof(int);
    int temp = sell_at_most_two_times(a, n);
    cout << temp;
    return 0;
}
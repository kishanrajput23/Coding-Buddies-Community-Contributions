#include <bits/stdc++.h>
using namespace std;
// question: a program to have the maximum profit in buying and selling the stocks. we can buy and sell stocks as many times we want. 

// Function to return the maximum profit
// that can be made after buying and
// selling the given stocks
// this code is written by me. 

// time complexity: O(N)
// space compelxity: O(1)
// int maximumProfit(int *a, int n)
// {
//     int mtemp = 0;
//     int temp = 0;
//     int profit = 0;
//     for (int i = 0; i <= n - 2; i++)
//     {
//         if (a[i] < a[i + 1])
//         {
//             mtemp = i + 1;
//         }
//         else if (a[i] == a[i + 1])
//         {
//             continue;
//         }
//         else
//         {
//             if (mtemp != 0)
//             {
//                 profit += a[mtemp] - a[temp];
//             }
//             temp = i + 1;
//             mtemp = 0;
//         }
//     }

//     if (mtemp == 0)
//     {
//         return profit;
//     }
//     else
//     {
//         profit += a[mtemp] - a[temp];
//         return profit;
//     }
// }

// this approach is from aman bhaiya you tube 
// this code is better. 
// time complexityy: O(N)
// space compelxity: O(1)
int maximumProfit(int* a, int n){
    int profit =0;
    for (int i = 1; i < n; i++)
    {
        if(a[i-1]<a[i]){
            profit += a[i]- a[i-1];
        }
    }
    return profit;
}
int main()
{
    int price[] = {7, 6, 5};
    int n = sizeof(price) / sizeof(price[0]);

    // cout << maxProfit(price, 0, n - 1);
    // cout << maximumProfit(price, n);
    // cout << maximumProfit(price, n)<<endl;


    return 0;
}
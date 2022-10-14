#include <bits/stdc++.h>
using namespace std;
// question: The best time to buy or sell a (single) stock. so that we could achieve maximum profit.

// appraoch1:
// time complexity: O(N**2)
// space complexity: O(1)
// int buy_or_sell_a_single_stock(int *a, int n)
// {
//     int maxProfit = 0;
//     for (int i = 0; i <= n - 2; i++)
//     {
//         for (int j = i + 1; j <= n - 1; j++)
//         {
//             if (a[j] - a[i] > maxProfit)
//             {
//                 maxProfit = a[j] - a[i];
//             }
//         }
//     }

//     if (maxProfit <= 0)
//     {
//         return 0;
//     }
//     else
//     {
//         return maxProfit;
//     }
// }

// approach 2:
// time complexity: O(N)
// space complexity: O(N)
// int buy_or_sell_a_single_stock(int *a, int n)
// {
//     int b[n];
//     int j = n - 1;
//     int maxSoFar = 0;
//     for (int i = n - 1; i >= 0; i--)
//     {
//         maxSoFar = max(a[i], maxSoFar);
//         b[j] = maxSoFar;
//         j--;
//     }
//     int maxprofit = 0;
//     for (int i = 0; i < n; i++)
//     {
//         int currprofit = b[i] - a[i];
//         if (currprofit > maxprofit)
//         {
//             maxprofit = currprofit;
//         }
//     }

//     return maxprofit;
// }

// approach 3: This is the most efficient approach to solve this problem.
// time compelxity: O(N)
// space compelxity: O(1)
// algorithm:
// har din hum isko sell karne ki koshish karenge aur dekhenge ki iska isse pehle minimum price kitna tha.
int buy_or_sell_a_single_stock(int *a, int n)
{
    int minSoFar = a[0];
    int maxProfit =0;
    for (int i = 1; i <=n-1; i++)
    {
        minSoFar = min(minSoFar, a[i]);
        int profit = a[i]- minSoFar;
        maxProfit = max(maxProfit, profit);
    }
    return maxProfit;
    
}
int main()
{
    int a[] = {5, 4, 6, 1, 9};
    int n = sizeof(a) / sizeof(int);
    cout << buy_or_sell_a_single_stock(a, n);
    return 0;
}

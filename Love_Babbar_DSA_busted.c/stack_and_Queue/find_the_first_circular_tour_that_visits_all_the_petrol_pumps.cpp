// #include <bits/stdc++.h>
// using namespace std;
// IMPORTANT 
// NOTE WHENEVER YOU WANT TO ṚEVISE THIS PROBLEM  GO TO 'APPLIED AI COURSE' YOU TUBE CHANNEL

// // This is the brute force approcah to solve this problem
// // This approach is made by me
// // time complexity: O(N^N)
// // space complexity: O(1)

// int petrol_pump(int n, vector<int> &p, vector<int> &d)
// {
//     int i = 0;
//     int r = 0;
//     int j = 0;
//     while (1)
//     {
//         if (i == n)
//         {
//             return -1;
//         }
//         if ((r + p[j]) > d[j])
//         {
//             r = ((r + p[j]) - d[j]);
//             j = ((j + 1) % n);
//             if (j == i)
//             {
//                 break;
//             }
//         }
//         else
//         {
//             i++;
//             r = 0;
//             j = i;
//         }
//     }
//     return i;
// }

// int petrol_pumpp(int n, vector<int> p, vector<int> d)
// {
//     int f = 0;
//     int r = 0;
//     int curr = 0;
//     while (1)
//     {
//         if (f == r && curr > 0)
//         {
//             return f;
//         }
//         if (curr < 0)
//         {
//             curr = 0;
//             f = r;
//             if (f == 0)
//             {
//                 return -1;
//             }
//         }

//         curr += p[r] - d[r];
//         r = (r + 1) % n;
//     }
// }
// int main()
// {
//     int n;
//     cin >> n;
//     vector<int> p;
//     for (int i = 0; i < n; i++)
//     {
//         int x;
//         cin >> x;
//         p.push_back(x);
//     }
//     vector<int> d;
//     for (int i = 0; i < n; i++)
//     {
//         int y;
//         cin >> y;
//         d.push_back(y);
//     }

//     cout << petrol_pumpp(n, p, d);
//     return 0;
// }






// this is the best approach made to solve this problem 
// time complexity: o(N)
// space complexity: O(1)
// see the video on you tube for this on applied ai course you tube 

// algorithm: 
// keep the track of the current petrol in the truck , 
// and also keep the track of the deficient petrol for the previous one's 
// at last if the current petrol and the deficient petrol sum is gretter than equal to zero so return the start index maintained earlier 
#include <bits/stdc++.h>
using namespace std;

int petrolPump(int n, int p[], int d[])
{
    int start = 0;
    int sum = 0;
    int diff = 0;
    for (int i = 0; i < n; i++)
    {
        sum += p[i] - d[i];
        if (sum < 0)
        {
            start = i + 1;
            diff = diff + sum;
            sum = 0;
        }
    }
    if ((sum + diff) >= 0)
    {
        return start;
    }
    return -1;
}

int main()
{
    int n= 5;

    int p[] = {6, 3, 7};
    int d[] = {4, 6, 3};
    cout << petrolPump(n, p, d);
    return 0;
}
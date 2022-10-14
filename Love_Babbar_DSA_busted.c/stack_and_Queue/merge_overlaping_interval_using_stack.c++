// #include <bits/stdc++.h>
// using namespace std;

// THE FIRST APPROACH TO THIS PROBLEM IS :
// 1. Sort the intervals based on increasing order of 
//     starting time.
// 2. Push the first interval on to a stack.
// 3. For each interval do the following
//    a. If the current interval does not overlap with the stack 
//        top, push it.
//    b. If the current interval overlaps with stack top and ending
//        time of current interval is more than that of stack top, 
//        update stack top with the ending  time of current interval.
// 4. At the end stack contains the merged intervals.
//TIME COMPLEXITY: O(NlogN)
// SPACE COMPLEXITY: O(N)
// int main()
// {
//     int n;
//     cin >> n;
//     vector<pair<int, int>> a;
//     for (int i = 0; i < n; i++)
//     {
//         int x, y;
//         cin >> x >> y;
//         a.push_back({x, y});
//     }
//     sort(a.begin(), a.end());
//     stack<pair<int, int>> s;
//     s.push({a[0].first, a[0].second});
//     for (int i = 1; i < n; i++)
//     {
//         int s1 = s.top().first;
//         int e1 = s.top().second;
//         int s2 = a[i].first;
//         int e2 = a[i].second;

//         if (e1 >= s2)
//         {
//             s.pop();
//             e1 = max(e1, e2);
//             s.push({s1, e1});
//         }
//         else
//         {
//             s.push({s2, e2});
//         }
//     }
//     cout << endl<< "After merging : " << endl;
//     while (!s.empty())
//     {
//         cout << s.top().first << " " << s.top().second << endl;
//         s.pop();
//     }

//     return 0;
// }



#include <bits/stdc++.h>
using namespace std;

// The most efficient approach is : 
// 1) Sort all intervals in increasing order of start time.
// 2) Traverse sorted intervals starting from first interval, 
//    do following for every interval.
//       a) If current interval is not first interval and it 
//          overlaps with previous interval, then merge it with
//          previous interval. Keep doing it while the interval
//          overlaps with the previous one.         
//       b) Else add current interval to output list of intervals.
// TIME COMPLEXITY: O(NlogN)
//  SPACE COMPLEXITY: O(1)
int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a;
    for (int j = 0; j < n; j++)
    {
        int x, y;
        cin >> x >> y;
        a.push_back({x, y});
    }
    sort(a.begin(), a.end());
    int index = 0;
    // int j=1;
    for (int i = 1; i < n; i++)
    {
        int s1 = a[index].first;
        int e1 = a[index].second;
        int s2 = a[i].first;
        int e2 = a[i].second;
        if (a[index].second >= a[i].first)
        {
            a[index].second = max(a[index].second, a[i].second);
        }
        else
        {
            index++;
            a[index].first = a[i].first;
            a[index].second = a[i].second;
        }
    }

    cout << endl;
    cout << "After merging : " << endl;
    for (int k = 0; k <= index; k++)
    {
        cout << a[k].first << " " << a[k].second << endl;
    }
    return 0;
}
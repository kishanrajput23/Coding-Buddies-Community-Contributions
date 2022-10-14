#include <bits/stdc++.h>
using namespace std;
// Iss sawal ne badaa dukhi kara par aakhri main ho hee gaya 
// Question: To find the largest area of a histogram 
//  1. brute force 
//  2. efficient approach : use of stack data structure 

// see the video for the algorithm if forgets 
// time complexity: O(N)
// space complexity: O(N)

int largest_area_of_a_histogram(vector<int> &a, int n)
{
    stack<int> s;
    // This stack stores index.
    int left[n];
    int right[n];
    int result[n];
    int i = 0;
    while (i != n)
    {
        if (s.empty())
        {
            left[i] = 0;
            s.push(i);
            i++;
        }
        else if (a[s.top()] < a[i])
        {
            left[i] = (s.top() + 1);
            s.push(i);
            i++;
        }
        else
        {
            s.pop();
        }
    }
    while (!s.empty())
    {
        s.pop();
    }

    i = (n - 1);
    while (i >= 0)
    {
        if (s.empty())
        {
            right[i] = n;
            s.push(i);
            i--;
        }
        else if (a[s.top()] < a[i])
        {
            right[i] = s.top();
            s.push(i);
            i--;
        }
        else
        {
            s.pop();
        }
    }
    for (int i = 0; i < n; i++)
    {
        result[i] = ((right[i] - left[i]) * a[i]);
    }
    int max = -1;
    for (int i = 0; i < n; i++)
    {
        if (result[i] > max)
        {
            max = result[i];
        }
    }

    return max;
}
int main()
{
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }

    cout << "The maximum area of the Histogram is " << largest_area_of_a_histogram(a, n) << endl;
    return 0;
}
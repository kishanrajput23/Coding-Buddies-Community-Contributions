// C++ program to find median of a matrix
// sorted row wise
#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;

int countSmallerThanEqualMid(vector<int> &row, int mid) {
    int l = 0, h = row.size() - 1;
    while(l <= h) {
        int md = (l + h) >> 1;
        if(row[md] <= mid) {
            l = md + 1;
        }
        else {
            h = md - 1;
        }
    }
    return l;
}
int findMedian(vector<vector<int> > &A) {
    int low = 100;
    int high = 155;
    int n = A.size();
    int m = A[0].size();
    while(low <= high) {
        int mid = (low + high) >> 1;
        int cnt = 0;
        cout<<mid<<endl;
        for(int i = 0;i<n;i++) {
            cnt += countSmallerThanEqualMid(A[i], mid);
        }
        cout<<cnt<<endl;
        if(cnt < ((n * m) / 2) + 1) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}

int main()
{
    // int r = 3, c = 3;
    vector<vector<int>> a = {{100, 102, 155}, {101, 105, 112}, {106, 108, 113}};
    cout << "Median is " << findMedian(a) << endl;
    return 0;
}

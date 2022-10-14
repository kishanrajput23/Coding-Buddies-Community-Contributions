#include <bits/stdc++.h>
using namespace std;

int binaryS(vector<vector<int>> &a, int indx, int n, int m, int r, int &res){
    int l = 0;
    int h = m-1;
    while(l<=h){
        int m = (l+h)>>1;
        if(a[r][m] == 1){
            h = m-1;
        }
        else{
            l = m+1;
        }
    }
    // indx = min(indx, l);
    if(indx> l){
        indx = l;
        res = r;
    }
    return indx;
}
int row_max_one(vector<vector<int>> &a, int n, int m){
    int indx = INT_MAX;
    int res;
    for(int r = 0;r<n;r++){
        if(indx == INT_MAX || indx == m){
            indx = binaryS(a, indx, n, m, r, res);
        }
        else if(a[r][indx] == 1){
            indx = binaryS(a, indx, n, m, r, res);
        }
    }
    if(indx == m){
        return -1;
    }
    // cout<<indx<<endl;
    return res;
}

int main()
{
    int n = 2;
    int m = 2;
    vector<vector<int>> a = {
        {0, 0},
        {0, 0}
    };

    int row_with_max_one_s = row_max_one(a, n, m);
    cout<<row_with_max_one_s<<endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define inf INT_MAX
typedef pair<int, int> ipair;

// time complexity: O(m + logn)
// space complexity: O(1)
int findItUtil(vector<vector<int>> &a, int m,int n, int sele, int r){
	int low = 0;
	int high = n-1;
	while(low<=high){
		int mid = (low+ high)/2;
		
		if(a[r][mid] == sele){
			return 1;
		}
		else if(a[r][mid] > sele){
			high = mid-1;
		}
		else if(a[r][mid]< sele){
			low = mid+ 1;
		}
	}
	return 0;
}
int findIt(vector<vector<int>> &a, int m, int n, int sele){
	int low = 0;
	int high = m-1;
	while(low<=high){
		int mid = (low+high)/2;

		if(a[mid][0] == sele){
			return 1;
		}

		if(a[mid][m-1] == sele){
			return 1;
		}

		if(a[mid][0]< sele and a[mid][m-1]> sele){
			int res = findItUtil(a, m, n, sele, mid);
			return res;
		}
		else if(a[mid][m-1]>sele){
			high = mid-1;
		}
		else if(a[mid][m-1]<sele){
			low = mid+1;
		}
	}
	return 0;
}

int main()
{
    vector<vector<int>> a = {
        {1, 2, 3, 7},
        {10, 11, 13, 15},
        {17, 18, 20, 22},
        {35, 38, 39, 42}
    };
    int sEle= 1;
    int m = a.size();
    int n = a[0].size();
    int res = findIt(a, m, n, sEle);
    cout<<res;
    return 0;
}


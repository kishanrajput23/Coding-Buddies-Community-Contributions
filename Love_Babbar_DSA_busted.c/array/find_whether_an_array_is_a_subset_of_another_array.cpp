#include <bits/stdc++.h>
using namespace std;

// write a program to know whether an array is subset of another array

// approach 1: 
// time compelxity: O(N^2)
// space complexity: O(1)

// approach 2 :
// algor : sort them and use the binary search. 
// time complexity: O(Nlog(N)+ Mlog(M))
// space compelxity: O(1)

// approach 3: 
// use map
// time complexity: O(N)
// space compelxity: O(N)
string isSubset(int* a1, int* a2, int n, int m){
    map<int, int> ma;
    for (int i = 0; i < n; i++)
    {
        ma[a1[i]]= i; // key: element , value: index
    }

    int count =0;
    for (int j = 0; j < m; j++)
    {
        if(ma.find(a2[j]) != ma.end()){
            count++;
        }
    }
    
    if(count == m){
        return "Yes";
    }
    return "No";
}
int main(){
    int a1[]= {2, 3, 6,1, 23};
    int a2[]= {23,  42, 3};
    int n = sizeof(a1)/sizeof(int);
    int m = sizeof(a2)/sizeof(int);
    string s = isSubset(a1, a2, n, m);
    cout<<s;
    return 0;
}
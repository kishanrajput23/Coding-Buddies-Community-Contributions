#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[]= {3,  3, 3,  34, 344, 2, 45};
    set<int> s(arr, arr+7);
    set<int> :: iterator itr;

    cout<<endl;
    cout<<s.size()<<endl;

    int a[]= {78, 88};
    s.insert(a, a+2);
    for(itr = s.begin();itr != s.end();itr++){
        cout<<*itr<<" ";
    }
    return 0;
}
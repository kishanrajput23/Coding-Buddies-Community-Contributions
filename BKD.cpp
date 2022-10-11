#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n,q;
    cin>> n >> q;
    cin.ignore();
    vector<vector<int>> a(n);
    for (int i = 0; i< n; i++){
        string line;
        getline(cin, line);
        istringstream ss(line);

        int k_size, k_item;
        ss>> k_size;
        vector<int> k(k_size, 0);
        for(int j= 0; j< k_size; j++) {
            ss>> k_item;
            k[j] =k_item;
        }  
        a[i] = k;    
    } 

    for (int i = 0; i<q; i++) {
        string query;
        getline(cin , query);
        istringstream ss(query);

        int x, y;
        ss>> x >> y;
        cout<< a.at(x).at(y) <<endl;
    }
    return 0;
}

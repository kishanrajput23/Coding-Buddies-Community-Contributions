#include <bits/stdc++.h>
using namespace std;
#define inf INT_MAX
typedef pair<int, int> ipair;
int n = 4;
int m = 4;

//************** I would prefer approach 2 for doing this. *******
// approachf 1:
// This is the recursive dfs method by which I had solved this question. 
// The code is written by me . 
// The idea is to use dfs to print the spiral order in clockwise dirn 
// call for all of it's adjacent and set a priority array from which the adjacent should start . 
// dry run the code for better understanding. 
// ** not seen from anywhere the idea is correct and got full points on gfg . **
// time complexity: O(m*n)
// space complexity: O(m*n)
void priorP(vector<int> &p, int i ){
    for(int j = 0;j<4;j++){
        if(i == j) p[j] = 1;
        else p[j] = 0;
    }
}

bool valid(int i, int j){
    if(i>=0 && j>=0 && i<m && j<n){
        return true;
    }
    return false;
}

bool isAllVis(vector<vector<int>> &vis){
    for(int i = 0;i<m;i++)
        for(int j = 0;j<n;j++)
            if(vis[i][j] == 0)
                return false;
    
    return true;
}
void dfsUtil(vector<vector<int>> &a, vector<vector<int>> &vis, vector<int> &p, vector<int> &di, vector<int> &dj, int gi, int gj){
    int f = 0;
    int i = 0;
    vis[gi][gj] = 1;
    if(isAllVis(vis)){
        cout<<a[gi][gj]<<" ";
        return;
    }
    while(1){
        i = (i+1)%4;
        if(p[i] == 1 || f){
            f = 1;
            int ni = gi+ di[i];
            int nj = gj+ dj[i];
            if(valid(ni, nj)){
                if(!vis[ni][nj]){
                    priorP(p, i);
                    cout<<a[gi][gj]<<" ";
                    dfsUtil(a, vis, p, di, dj, ni, nj);
                    return;
                }
            }
        }
    }
}
void dfs(vector<vector<int>> &a){
    if(m == 1 && n == 1){
        cout<<a[0][0];
        return;
    } 
    vector<vector<int>> vis(m, vector<int> (n, 0));
    vector<int> p(4, 0);
    vector<int> di = {0, 1, 0, -1};
    vector<int> dj = {1, 0, -1, 0};

    if(valid(0, 1)){
        p[0] = 1;
    }
    else if(valid(1, 0)){
        p[1] = 1;
    }

    dfsUtil(a, vis, p, di, dj, 0, 0);
}

// method 2
// This is a very good method 
// seen this from pepcoding sir. 
// The logic is amazing 
// *****In this I had printed the code spirally anticlockwise ******
// algo: 
// try to observe the pattern and print the first outer most box 
// and iteratively call for it. 
// time complexity: O(n*m)
// space complexity: O(!)
void spiral_traversal_method2(vector<vector<int>> &a){
    int m = a.size();
    int n = a[0].size();
    int totalElements = m*n;
    int currCount = 0;
    int minr = 0;
    int maxr = m-1;
    int minc = 0;
    int maxc = n-1;
    while(totalElements>currCount){

        // left wall 
        for(int i = minr, j= minc;i<=maxr && currCount<totalElements;i++){
            cout<<a[i][j]<<" ";
            currCount++;
        }
        minc++;

        // bottom wall 
        for(int j = minc, i= maxr;j<=maxc && currCount<totalElements;j++){
            cout<<a[i][j]<<" ";
            currCount++;
        }
        maxr--;

        // right wall 
        for(int i = maxr, j= maxc;i>=minr && currCount<totalElements;i--){
            cout<<a[i][j]<<" ";
            currCount++;
        }
        maxc--;

        // left wall 
        for(int j = maxc, i= minr;j>=minc && currCount<totalElements;j--){
            cout<<a[i][j]<<" ";
            currCount++;
        }
        minr++;
    }
}
int main()
{
    vector<vector<int>> a={
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    dfs(a);
    cout<<endl;
    spiral_traversal_method2(a);
    return 0;
}
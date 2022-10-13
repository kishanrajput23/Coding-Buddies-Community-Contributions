#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
#define int ll
#define pb push_back
#define INF 2e18
#define mp make_pair
typedef long long ll;
typedef long double ld;
ll MOD = 998244353;
double eps = 1e-12;
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
class Node{
    public: 
    int data;
    int liss;
    Node*left;
    Node*right;
    Node(int  val){
        liss  = -1;
        data= val;
        left = NULL;
        right = NULL;
    }
};

// approach 1: 
// this is simple recursion problem, 
// you need to find the largest independent set . an independent set is a set which do not have any direct edge between them. 
// this is naive approach so complexity is exponential. 
// algo: 
// include yourself as a node and select their grandchildren, or do not include yourself include your direct children, have the maximum out of them. 
// time complexity:O(6^n) this is exponential. 
// space complexity:O(1) ignoring recursion stack. 
// int solve(Node* root){
//     if(root == NULL) return 0;
//     int var1, var2;
//     var1 = 0;
//     var2 = 1;
//     var1 = solve(root->left)+solve(root->right);
//     if(root->left) var2 += solve(root->left->left)+solve(root->left->right);
//     if(root->right) var2+= solve(root->right->left)+solve(root->right->right);
//     return max(var1, var2);
// }

Node* newNode(int data){
    Node* temp = new Node(data);
    return temp;
}

// approach 2: 
// the approach is same as one , but we are using here dynamic programming on trees . 
// create a int liss itself in it's class Node, 
// time complexity:O(N)
// space complexity:O(1) ignoring recursion stack. 
int solve(Node* root){
    if(root == NULL) return 0;
    if(root->liss!= -1) return root->liss;
    int var1 = 0;
    int var2 = 1;
    var1 = solve(root->left)+solve(root->right);
    if(root->left) var2 += solve(root->left->left)+solve(root->left->right);
    if(root->right) var2 += solve(root->right->left)+solve(root->right->right);
    return root->liss = max(var1, var2);
}
int32_t main()
{
    fast_cin();
    Node* root = newNode(10);
    root->left = newNode(20);
    root->right = newNode(30);
    root->left->left = newNode(40);
    root->left->right = newNode(50);
    root->right->right = newNode(60);
    root->left->right->left = newNode(70);
    root->left->right->right = newNode(80);
    int res = solve(root);
    cout<<res<<endl;
    return 0;
}
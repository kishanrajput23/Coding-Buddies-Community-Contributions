#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll
#define mp make_pair
#define pb push_back
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
ll MOD = 998244353;
double eps = 1e-12;
// I had used the name bottom instead of random . 
// this is a tricky question to think and also hard to implement. see the logic from the anuj bhaiya video and I had code it myself and submitted on gfg and leetcode as well 
// time complexity:O(N)
// space complexity:O(1)
struct Node
{
    int data;
    Node *next;
    Node* bottom;
    Node(){
        data = 0;
        next = NULL;
        bottom = NULL;
    }
    Node(int data){
        this->data = data;
        next = NULL;
        bottom = NULL;
    }
};

void linkedLL(Node *head)
{
    Node *ptr = head;
    // cout<<ptr->bottom->data<<endl;
    cout<<"For random pointer"<<endl;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->bottom;
    }
    cout << endl<<endl;
    cout<<"For next pointer"<<endl;
    ptr = head;
    while(ptr != NULL){
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    cout<<endl<<endl;
}
Node* newNode(int data){
    Node* temp = new Node(data);
    return temp;
}
Node* cloneIt(Node* head){
    Node* p = NULL;
    Node* q = NULL;
    Node* ptr = head;
    Node* nHead;
    while(ptr != NULL){
        Node* t = new Node(ptr->data);
        p = q;
        q = t;
        ptr = ptr->next;
        if(p!= NULL) p->next = q;
        else nHead = q;
    }
    Node* h1 = head;
    Node* h2 = nHead;
    Node* c2 = nHead->next;
    while(h1 != NULL and h2!= NULL){
        h2->next = h1->next;
        h1->next = h2;
        h1 = h1->next->next;
        h2 = c2;
        if(c2!= NULL) c2 = c2->next;
    }
    h1 = head;
    h2 = nHead;
    while(h1!= NULL and h2 != NULL){
        if(h1->bottom != NULL){
            h2->bottom = h1->bottom->next;
        }
        if(h2->next != NULL){
            h2 = h2->next->next;
        }
        if(h1->next != NULL){
            h1 = h1->next->next;
        }
    }
    h1 = head;
    h2 = nHead;
    while(h2 != NULL){
        h1->next = h1->next->next;
        if(h1->next == NULL){
            h2->next = NULL;
            break;
        }
        else{
            h2->next = h2->next->next;
        }
        h1 = h1->next;
        h2 = h2->next;
    }
    return nHead;
}
int32_t main()
{
    Node* h1 = newNode(1);
    h1->next = newNode(2);
    h1->next->next = newNode(3);
    h1->next->next->next = newNode(4);
    h1->bottom = h1->next;
    h1->next->bottom = h1->next->next->next;
    Node* h = cloneIt(h1);
    linkedLL(h);
    return 0;
}
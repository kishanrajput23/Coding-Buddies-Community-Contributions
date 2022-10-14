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
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->bottom;
    }
    cout << endl;
}
int fSize(Node *head)
{
    Node *ptr = head;
    int c = 0;
    while (ptr != NULL)
    {
        c++;
        ptr = ptr->next;
    }
    return c;
}

// Node* reverseIt(Node* head){
//     if(head == NULL) return NULL;
//     if(head->next == NULL) return head;
//     Node* p = NULL;
//     Node* q = head;
//     Node* r = head->next;
//     while(q != NULL){
//         q->next = p;
//         q->prev = r;
//         p = q;
//         q = r;
//         if(r!= NULL)r = r->next;
//     }
//     return p;
// }

// Node* reverseItByKNodes(Node* head,int k){
//     if(head == NULL) return NULL;
//     if(head->next == NULL) return head;
//     Node* p = NULL;
//     Node* q = head;
//     Node* r = head->next;
//     for(int i = 0;q!= NULL and i<k;i++){
//         q->next = p;
//         q->prev = r;
//         p = q;
//         q = r;
//         if(r != NULL) r = r->next;
//     }
//     head->next = reverseItByKNodes(q, k);
//     return p;
// }
Node* newNode(int data){
    Node* temp = new Node(data);
    return temp;
}

// struct comp{
//     bool operator()(Node* p1, Node* p2){
//         return p1->data>p2->data;
//     }
// };

// Node* f(Node* head,int k){
//     int n = fSize(head);   
//     if(n==k){
//         head = reverseIt(head);
//         return head;
//     }
//     Node* p = head;
//     Node* q = head;
//     Node* r = head;
//     Node* s = head;
//     while(k--){
//         q = r;
//         r = r->next;
//     }
//     s = r;
//     while(s->next != NULL) s = s->next;
//     q->next = NULL;
//     r->prev = NULL;
//     q = reverseIt(p);
//     s = reverseIt(r);
//     p->next = s;
//     s->prev = p;
//     head = reverseIt(q);
//     return head;
// }

// aproach 1: 
// This gives tle
// algo: I have travelled through each and every next pointer and find the samllest out of them and then rechange the pointers. 
// tle on gfg portal don't use this approach. use approach 2. 
Node* flatten(Node* head){
    Node* nH = head;
    Node* H = head;
    Node* p = NULL;
    Node* q = head;
    Node* r = NULL;
    while(H!= NULL){
        // cout<<H->data<<endl;
        Node* temp = H;
        q = H;
        Node* prev = NULL;
        int val = H->data;
        Node* temprev = NULL;
        while(temp!= NULL){
            // cout<<temp->data<<" ";
            if(temp->data<val){
                val = temp->data;
                prev = temprev;
                q = temp;
            }
            temprev = temp;
            temp = temp->next;
        }
        // cout<<endl;
        // cout<<q->data<<endl;
        if(q->bottom == NULL){
            r = q;
            q = q->next;
            if(prev != NULL) prev->next = q;
            else H = q;
            if(p == NULL) p = nH;
            else{
                p->next = r;
                p = r;
            }
        }
        else{
            q->bottom->next = q->next;
            // cout<<q->data<<endl;
            // if(q->bottom->next != NULL)cout<<q->bottom->next->data<<endl;
            r = q;
            q = q->bottom;
            if(prev != NULL) prev->next = q;
            else H = q;
            if(p == NULL) p = nH;
            else{
                p->next = r;
                p = r;
            }
            r->next = NULL;
            r->bottom = NULL;
        }
    }
    return nH;
}

// approach 2: 
// this question is very simple as it could be reduced to merge 2 sorted linked list without using any extra space . 
// see striver bhaiya video for merging them. 
Node* mergeSorted(Node* h1, Node* h2){
    if(h1 == NULL) return h2;
    if(h2 == NULL) return h1;
    if(h1->data>h2->data){
        Node* temp = h1;
        h1 = h2;
        h2 = temp;
    }
    Node* head = h1;
    while(h1 != NULL and h2!= NULL){
        Node* prev = NULL;
        while(h1 != NULL and h2 != NULL and h1->data<=h2->data){
            prev = h1;
            h1 = h1->bottom;
        }
        prev->bottom = h2;

        // swap them 
        Node* temp = h1;
        h1 = h2;
        h2 = temp;
    }
    return head;
}
Node* flattenIt(Node* head){
    Node* p = head;
    Node* q = head->next;
    while(q != NULL){
        p = mergeSorted(p, q);
        q = q->next;
    }
    return p;
}
int32_t main()
{
    Node* h1 = newNode(5);
    h1->bottom = newNode(7);
    h1->bottom->bottom = newNode(8);
    h1->bottom->bottom->bottom = newNode(30);
    h1->next = newNode(10);
    // h1->next->bottom = newNode(20);
    h1->next->next = newNode(19);
    h1->next->next->bottom = newNode(22);
    h1->next->next->bottom->bottom = newNode(50);
    h1->next->next->next = newNode(28);
    // h1->next->next->next->bottom = newNode(35);
    // h1->next->next->next->bottom->bottom = newNode(40);
    // h1->next->next->next->bottom->bottom->bottom = newNode(45);

    // Node* temp = h1;
    // Node* temp2 = h1;
    // while(temp != NULL){
    //     temp2 = temp;
    //     while(temp2 != NULL){
    //         cout<<temp2->data<<" ";
    //         temp2 = temp2->bottom;
    //     }
    //     cout<<endl;
    //     temp = temp->next;
    // }
    // h1->next->prev = h1;
    // h1->next->next = newNode(2);
    // h1->next->next->prev = h1->next;
    // h1->next->next->next = newNode(12);
    // h1->next->next->next->prev = h1->next->next;
    // h1->next->next->next->next = newNode(56);
    // h1->next->next->next->next->prev = h1->next->next->next;
    // h1->next->next->next->next->next = newNode(8);
    // h1->next->next->next->next->next->prev = h1->next->next->next->next;

    // h1->next->next->next->next->next = newNode(5);
    // h1->next->next->next->next->next->next = newNode(100);
    // h1->next->next->next->next->next->next->next = newNode(3);
    // h1->next->next->next->next->next->next->next->next = newNode(2);
    // h1->next->next->next->next->next->next->next->next->next = newNode(1);

    Node* h2 = newNode(9);
    h2->next = newNode(10);

    // linkedLL(h1);
    // linkedLL(h2);
    // Node* h3 = mergeSorted(h1, h2);
    // mergeSort(h1);
    // linkedLL(h1);
    // int k = 3;
    // cout<<isPalindrome(h1)<<endl;
    h1 = flattenIt(h1);
    linkedLL(h1);
    // for(auto x: v){
    //     linkedLL(x);
    // }

    // linkedLL(h3);
    return 0;
}
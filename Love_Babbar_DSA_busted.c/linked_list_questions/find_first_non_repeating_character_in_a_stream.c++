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

struct Node{
    char a;
    Node* next;
    Node* prev;
    Node(char b){
        a = b;
        next = NULL;
        prev = NULL;
    }
};
// this is a hard question and not intutive see tech dose sir video this approach is the most optimised one but I don't know why gfg compiler is giving tle on it. 
// time complexity:O(N)
// space complexity:O(26)
void append(Node* &head, Node* &tail, char a){
    Node* temp = new Node(a);
    if(head == NULL){
        head = temp;
        tail = temp;
    }
    else{
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void remove(Node* &head, Node* &tail, Node* temp){
    if(temp == head){
        head = head->next;
    }
    else if(temp == tail){
        temp->prev->next = NULL;
        tail = temp->prev;
        temp->prev = NULL;
    }
    else{
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        temp->next = NULL;
        temp->prev = NULL; 
    }
}
string f(string s){
    string res = "";
    int n = s.size();
    vector<bool> repeat(26, false);
    vector<Node*> address(26, NULL);
    Node* head = NULL;
    Node* tail = NULL;
    for(int i = 0;i<n;i++){
        if(!repeat[s[i]-'a']){
            if(address[s[i]-'a']== NULL){
                append(head, tail, s[i]);
                address[s[i]-'a'] = tail;
            }
            else{
                remove(head, tail, address[s[i]-'a']);
                address[s[i]-'a'] = NULL;
                repeat[s[i]-'a'] = true;
            }
        }

        if(head != NULL){
            res = res + head->a;
        }
        else{
            res = res + '#';
        }
    }
    return res;
}

// approach 2: this is the much simpler approach but takes more time but I don't know why gfg compiler gets successfull on it. gfg compiler is shit. 
// time complexity:O(26*N)
// space complexity:O(26)
string FirstNonRepeating(string str){
    string ans = "";
    deque<char> dq;
    int hash[26]={0};
    for(auto it:str){
        if(hash[it-'a'] == 0)dq.push_back(it);
        hash[it-'a']++;
        while(!dq.empty() and hash[dq.front() - 'a'] != 1) dq.pop_front();
        if(dq.empty()) ans += '#';
        else ans += dq.front();   
    }
    return ans;
}
int32_t main()
{
    string s = "cabbabc";
    string res = f(s);
    cout<<res<<endl;
    return 0;
}
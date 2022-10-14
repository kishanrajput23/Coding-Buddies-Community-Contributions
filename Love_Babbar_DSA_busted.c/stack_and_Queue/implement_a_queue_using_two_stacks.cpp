// #include <bits/stdc++.h>
// using namespace std;

// In this push is costlier 
// time complexity: push : O(N)
                    // pop : O(1)
// class Queue
// {
//     int n;
//     stack<int> s1;
//     stack<int> s2;

//     public:
//     Queue()
//     {
//         n = 0;
//     }
//     void push(int val)
//     {
//         n++;
//         while (!s1.empty())
//         {
//             int temp = s1.top();
//             s1.pop();
//             s2.push(temp);
//         }
//         s1.push(val);

//         while(!s2.empty()){
//             int var = s2.top();
//             s2.pop();
//             s1.push(var);
//         }
//     }

//     int pop(){
//         int variable = s1.top();
//         s1.pop();
//         n--;
//         return variable;
//     }

//     int size(){
//         return n;
//     }

//     int front(){
//         return s1.top();
//     }
// };
// int main()
// {
//     Queue q;
//     q.push(1);
//     q.push(2);
//     q.push(3);
//     cout<<q.pop()<<endl;
//     return 0;
// }




// Here pop is costlier 
// push: O(1)
// pop: O(N)
#include<bits/stdc++.h>
using namespace std;

class Queue{
    int n;
    stack<int> s1;
    stack<int> s2;

    public: 
    Queue(){
        n=0;
    }

    void push(int val){
        n++;
        s1.push(val);
    }

    int pop(){
        while(s1.size() != 1){
            int val= s1.top();
            s1.pop();
            s2.push(val);
        }
        int var = s1.top();
        s1.pop();

        while(!s2.empty()){
            int vari = s2.top();
            s2.pop();
            s1.push(vari);
        }
        n--;
        return var;
    }
};
int main(){

    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    return 0;
}
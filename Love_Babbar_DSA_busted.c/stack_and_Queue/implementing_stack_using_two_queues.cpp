// #include <bits/stdc++.h>
// using namespace std;

// // Here push operation is costlier for me
// // push: O(N)
// // pop: O(1)
// class Stack
// {
//     int n;
//     queue<int> q1;
//     queue<int> q2;

//     public:
//     stack()
//     {
//         n = 0;
//     }
//     void push(int val)
//     {
//         q2.push(val);
//         while (!q1.empty())
//         {
//             q2.push(q1.front());
//             q1.pop();
//         }
//         while (!q2.empty())
//         {
//             q1.push(q2.front());
//             q2.pop();
//         }
//         n++;
//     }

//     int pop()
//     {
//         int val = q1.front();
//         q1.pop();
//         n--;
//         return val;
//     }

//     int top(){
//         return q1.front();
//     }

//     int size(){
//         return n;
//     }
// };

// int main()
// {
//     Stack s;
//     s.push(2);
//     s.push(3);
//     s.push(4);
//     cout<<s.top()<<endl;
//     cout<<s.pop()<<endl;
//     cout<<s.top()<<endl;
//     cout<<s.pop()<<endl;
//     cout<<s.pop()<<endl;

//     return 0;
// }




#include <bits/stdc++.h>
using namespace std;

// Here pop operation is costlier 
// pop: O(N)
// push: O(1)
class Stack
{
    int n;
    queue<int> q1;
    queue<int> q2;

public:
     Stack()
    {
        n = 0;
    }

    void push(int val)
    {
        q1.push(val);
    }

    int pop()
    {
        while (q1.front() != q1.back())
        {
            int a = q1.front();
            q1.pop();
            q2.push(a);
        }
        int val= q1.front();
        q1.pop();
        while (!q2.empty())
        {
            int a = q2.front();
            q2.pop();
            q1.push(a);
        }
        return val;
    }
};
int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    return 0;
}
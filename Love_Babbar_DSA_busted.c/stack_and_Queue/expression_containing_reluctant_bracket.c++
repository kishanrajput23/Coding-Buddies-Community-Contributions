#include <bits/stdc++.h>
using namespace std;
// Time complexity: O(N)
//space complexity: O(N)
int main()
{
    bool ans = false;
    string a = "(a+(b))";
    stack<int> s;

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == ')')
        {
            if (s.top() == '(')
            {
                ans = true;
                break;
            }
            else
            {
                while (s.top() != '(')
                {
                    s.pop();
                }
                s.pop();
            }
        }
        if (a[i] == '(' or a[i] == '+' or a[i] == '-' or a[i] == '*' or a[i] == '/')
        {
            s.push(a[i]);
        }
    }
    if(ans){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<int, int> m;
    m[1] = 2;
    m[5] = 3;
    m[3] = 46;
    m[2] = 33;

    map<int, int>::iterator i;

    for (i = m.begin(); i != m.end(); i++)
    {
        cout << i->first << "->" << i->second << endl;
    }

    cout << endl;

    unordered_map<int, int> M;
    M[1] = 2;
    M[5] = 3;
    M[4] = 46;
    M[2] = 33;

    unordered_map<int, int> :: iterator it;

    for(it = M.begin();it != M.end();it++)
    {
        cout<<it->first<<"->"<<it->second<<endl;
    }

    return 0;
}
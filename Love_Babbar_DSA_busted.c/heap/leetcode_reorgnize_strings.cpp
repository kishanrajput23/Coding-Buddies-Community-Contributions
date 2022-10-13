#include <bits/stdc++.h>
using namespace std;

// we can also solve this problem with the priority_queue but the complexity will be more 





// the most efficient appraoch to solve this problem 
// time complexity: O(N)
// space complexity:O(N)
// algo : 
// simply store the characters and their frequency in a unordered map
// then find the element with the maximum frequency
// then put all the characters with maximum frequency at their even positions 
// then put rest of the elements 
// read gfg article for this better understanding. 
string sR(string s)
{
    unordered_map<char, int> m;
    int n = s.size();
    for (int i = 0; i < s.size(); i++)
    {
        m[s[i]]++;
    }

    int mf = 0;
    char mch = '#';
    for( auto x:m)    
    {
        if(mf<x.second)
        {
            mch = x.first;
            mf = x.second;
        }
    }

    // cout<<mf<<" "<<mch<<endl;
    
    if(mf> (n+1)/2)
    {
        return "Invalid";
    }
    int indx = 0;
    string res(n, ' ');

    while (mf--)
    {
        res[indx] = mch;
        indx = indx + 2;
    }
    
    m[mch] = 0;

    for(auto x:m)
    {
        while(x.second--)
        {
            if(indx>=n)
            {
                indx = 1;
            }

            res[indx] = x.first;
            indx = indx+2;
        }
    }
    return res;
}

int main()
{
    string s = "abcaaaaaapqrstuv";
    string res = sR(s);
    cout<<res;

    return 0;
}
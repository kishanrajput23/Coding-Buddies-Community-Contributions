class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>dict(256,-1);
        int strt=-1,mxln=0;
        for(int i=0;i<s.length();i++)
        {
            if(dict[s[i]]>strt)
            {
                strt=dict[s[i]];
            }
            dict[s[i]]=i;
            mxln=max(mxln,i-strt);
        }
        return mxln;
    }
};

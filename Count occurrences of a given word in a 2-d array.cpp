class Solution{
    public:
    void check(int i,int j,int n,int m,vector<vector<char>>&a,vector<vector<int>>&visited,string target,int pos,int &count)
    {
        if(i<0||i>=n||j<0||j>=m||visited[i][j]||a[i][j]!=target[pos])
        return;
        
            visited[i][j]=1;
            if(pos==target.length()-1)
        {
            count++;
        }
            check(i+1,j,n,m,a,visited,target,pos+1,count);
            check(i,j+1,n,m,a,visited,target,pos+1,count);
            check(i-1,j,n,m,a,visited,target,pos+1,count);
            check(i,j-1,n,m,a,visited,target,pos+1,count);
            visited[i][j]=0;
         
    }
    int findOccurrence(vector<vector<char> > &a, string target){
        int n=a.size(),m=a[0].size();
        int count=0,pos=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                 vector<vector<int>>visited(n,vector<int>(m,0));
                if(target[0]==a[i][j])
                check(i,j,n,m,a,visited,target,0,count);
            }
        }
        return count;
    }
};

class Solution{
    public:
    int maximizeSum(int a[], int n) 
    {
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            m[a[i]]++;
        }
        int sum=0;
        for(int i=n-1;i>=0;i--){
            if(m[a[i]] > 0 )
          {  sum+=a[i];
            m[a[i]]--;
              if(m.find(a[i]-1)!=m.end() ) m[a[i]-1]--;
          }
        }
        return sum;
    }

};

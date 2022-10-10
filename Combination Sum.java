class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> list= new ArrayList<List<Integer>>();
        
        int[] a = new int[41];
        for(int x:candidates)
        a[x]=1;
       
        int i=0;
        int j=0;
        for(int x:a)
        {
            if(x==1)
            candidates[j++]=i;
            i++;
        }
        
        find(list,candidates,target,new ArrayList<Integer>(),0);
        return list;
    }
    
    
    private void find(List<List<Integer>> list,int[] candidates,int target,ArrayList<Integer> temp,int start)
    {
        if(target==0)
        {
            list.add(new ArrayList<Integer>(temp));
            return;
        }
        
        for(int i=start;i<candidates.length;i++)
        {
            if(target-candidates[i]>=0)
            {
                temp.add(candidates[i]);
                find(list,candidates,target-candidates[i],temp,i);
                temp.remove(temp.size()-1);
            }
        }
    }
}

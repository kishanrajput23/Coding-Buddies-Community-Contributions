class Solution {
public:
    int longestValidParentheses(string s) {
        int open=0, close=0;
        int maxLen=0;
		
		//traversing from left
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                open++;
            }
            else{
                close++;
            }
			//valid pair of paranthesis if number of opening and closing brackets are equal
            if(open==close){   
                int len=open+close;
                maxLen=max(maxLen,len);
            }
			else if(close>open){      //from left if closing brackets is greater than openin brackets
                close=0;
                open=0;
            }
        }
        
        open=0,close=0;
        
		//traversing from right
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='('){
                open++;
            }
            else{
                close++;
            }
			//valid pair of paranthesis if number of opening and closing brackets are equal
            if(open==close){
                int len=open+close;
                maxLen=max(maxLen,len);
            }
            else if(close<open){     //from right if opening brackets is greater than closing brackets
                close=0;
                open=0;
            }            
        }
        return maxLen;
    }
};

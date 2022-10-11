class Solution(object):
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        
        while s[-1] == " ":
            s = s[:-1]
        
        index = -1
        char = s[index]
        res = 0
        
        while char != " ":
            print(char)
            res += 1
            index -= 1
            if abs(index) == len(s) + 1:
                return res
            char = s[index]
        
        return res

# My Solution for LeetCode 20 - Valid Parentheses

class Solution:
    def isValid(self, s: str) -> bool:
        stk = [] # For holding all the characters
        temp = [] # For holding temporary characters till we find their equivalent 

        # Build the stack
        for c in s:
            stk.append(c)
        
        # We pop at the beginning
        temp.append(stk.pop()) # Put the character into temporary

        while(stk): # While the stack is not empty
            
            #print(f'stk : {stk} temp : {temp}')
            if temp:
                if temp[-1] == ')' and stk[-1] == '(':
                    temp.pop()
                    stk.pop()
                    continue
                elif temp[-1] == ']' and stk[-1] == '[':
                    temp.pop()
                    stk.pop()
                    continue
                elif temp[-1] == '}' and stk[-1] == '{':
                    temp.pop()
                    stk.pop()
                    continue
            
            temp.append(stk.pop())
                
        if(temp):
            return False

        return True
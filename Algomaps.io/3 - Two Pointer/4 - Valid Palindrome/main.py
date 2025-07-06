# My solution for LeetCode 125 Valid Palindrome using Python

# Version 1 : 
class Solution:
    def isPalindrome(self, s: str) -> bool:
        r = [] # create buffer for new string

        for c in s:
            if c.isalnum():
                r.append(c.lower())
        
        s = "".join(r)

        # Solution using 2 pointer
        i, j = 0, len(s) - 1
        while i <= j:
            # Check the characters
            if s[i] != s[j]:
                return False
            # update the pointers
            i += 1
            j -= 1
        
        return True
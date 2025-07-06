# Solution from algomap.io
class Solution:
    def isPalindrome(self, s: str) -> bool:
        # Solution using 2 pointer
        i, j = 0, len(s) - 1

        while i <= j:
            if not s[i].isalnum():
                i += 1
                continue
            if not s[j].isalnum():
                j -= 1
                continue
            # We will only reach this block when both the
            # characters are alnums
            # Check the characters
            if s[i].lower() != s[j].lower():
                return False
            # update the pointers
            i += 1
            j -= 1
        
        return True
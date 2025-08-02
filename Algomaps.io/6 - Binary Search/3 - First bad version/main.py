# My solution for Leetcode - 278 (First bad Version)

# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:

class Solution:
    def firstBadVersion(self, n: int) -> int:
        # Condition based Binary Search
        # Make sure to update R = M
        # and to check loop condition for L < R
        # Since at some point all L R M will be have the same 
        # value and we specifically want that value
        L = 1 # min = 1
        R = n # max = n

        while L < R:
            M = L + ((R - L) // 2)

            if isBadVersion(M): # If this return true then we want to update the R
                R = M
            else:
                L = M + 1
        
        return L # This will point to the first False


        
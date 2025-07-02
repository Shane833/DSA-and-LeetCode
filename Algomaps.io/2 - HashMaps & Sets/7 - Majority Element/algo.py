# Linear Solution from algomap.io 

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
      ans = -1
      count = 0
    
     # Linearly goes through the array and maintain an active count
     # of the elements, If the elements appears more than half times
     # then it will be the ans in the end

      for n in nums:
        if count == 0:
            ans = n
        
        if ans == n:
            count += 1
        else:
            count -= 1
    
      return ans

    # Time Complexity : O(n)
    # Space Complexity : O(1)
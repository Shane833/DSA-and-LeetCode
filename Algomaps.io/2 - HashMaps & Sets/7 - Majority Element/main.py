# My solution for LeetCode 169 - Majority Element
from collections import defaultdict

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        count = defaultdict(int)
        # Create a count
        for n in nums:
            count[n] += 1
        # Find the key with the max value
        maj = nums[0]       
        for k in count:
            if count[k] > count[maj]:
                maj = k
        
        return maj
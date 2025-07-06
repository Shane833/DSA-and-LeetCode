# Solution from algomap.io
class Solution:
    def findClosestNumber(self, nums: List[int]) -> int:
        result = nums[0]
        for i in nums:
            if abs(i) < abs(result):
                result = i
        
        if result < 0 and abs(result) in nums:
            return abs(result)
        else:
            return result
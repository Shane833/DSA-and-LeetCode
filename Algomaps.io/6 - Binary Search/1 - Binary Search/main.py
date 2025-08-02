# My solution for Leetcode 704 - Binary Search
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        low = 0
        high = len(nums) - 1

        while low <= high:
            middle = (low + high) // 2

            if target < nums[middle]:
                high = middle - 1
            elif target > nums[middle]:
                low = middle + 1
            else:
                return middle
        
        return -1
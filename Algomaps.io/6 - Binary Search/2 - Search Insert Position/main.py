# My solution for LeetCode - 35 (Search Insert Position)

class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        N = len(nums)
        L = 0
        R = N - 1

        while L <= R:
            M = L + ((R - L) // 2)

            if target < nums[M]:
                R = M - 1
            elif target > nums[M]:
                L = M + 1
            else:
                return M
            
        return L
        
        
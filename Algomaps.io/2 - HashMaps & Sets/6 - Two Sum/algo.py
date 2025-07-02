# Solution for LeetCode 1 - Two Sum using hashmaps

from collections import defaultdict

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # How can hashmaps be of use here?
        idict = {}
        # create a hashmap values, indices
        for i in range(len(nums)):
            idict[nums[i]] = i
        
        # Then we go sequentially and keep subtracting
        # the keys from the target and check if the result
        # of that subtraction exists in the map
        # If yes then we create a list with both the indices
        # If not then we simply look ahead

        for i in range(len(nums)):
            y = target - nums[i]

            if y in idict and idict[y] != i:
                return [idict[y],i]

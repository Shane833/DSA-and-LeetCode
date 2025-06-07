# LEETCODE 228

def summaryRanges(nums):
    ans = [] # This stores our ans
    i = 0

    while i < len(nums): # Protecting from index out of bound
        start = nums[i] # We create a start variable which holds the current value at the beginning of the loop

        # Here we check 2 conditions
        # 1. Since we are looking ahead by one we want to make sure that i is within bound and hence we limit it to len(nums) - 1
        # 2. We want to make sure the no.s are consecutive, so we check nums[i] + 1 == nums[i+1]
        while i < len(nums) - 1 and nums[i] + 1 == nums[i+1]:
            i += 1 # and we keep incrementing i until these conditions are satisfied
        
        # When we come out of the inner loop we want to check
        # if we are where we started, i.e. if nums[i] == start or not
        # If its not we append a range
        if start != nums[i]:
            ans.append(str(start) + '->' + str(nums[i]))
        else: # If they are indeed the same we append the single variable
            ans.append(str(nums[i]))
    
        i += 1 # and at the end of the loop we increment i again
    
    return ans

# LEETCODE PROBLEM - 228
def summaryRanges(nums):
    
    result = [] # final list to be returned at the end
    
    # We check the length of the nums list
    if len(nums) > 1:
        i = 1 # iterator for the loop
        temp = [] # temporary list for holding values
        while i < len(nums):
            if nums[i] - nums[i - 1] == 1: # if no.s are consecutive
                if i == len(nums) - 1: # if no. at i is not consecutive w.r.t to its preceeding no. and its the last element
                    temp.append(nums[i - 1]) # We add them to the temporary lits
                    temp.append(nums[i])
                    if len(temp) > 1: # if we have multiple ranges
                        result.append(str(temp[0]) + "->" + str(temp[-1])) # We combine the first and last element and append it to the result
                
                temp.append(nums[i - 1]) # We add them to the temporary lits
                
                
            else: # If they are not consecutive
                temp.append(nums[i - 1]) # we append the preceding item since it was consecutive
                if len(temp) > 1: # if we have multiple ranges
                    result.append(str(temp[0]) + "->" + str(temp[-1])) # We combine the first and last element and append it to the result
                elif len(temp) == 1: # if there is only a single element in the temp
                    result.append(str(temp[0]))
                
                temp = [] # we empty out the temp for other elements
                
                if i == len(nums) - 1: # if no. at i is not consecutive w.r.t to its preceeding no. and its the last element
                    result.append(str(nums[i]))
                
            i += 1 # increment the loop variable
    
    elif len(nums) == 1: # If there is only a single element
        result.append(str(nums[0]))
    
    return result # we simply result the list also works if len(nums) == 0


# Test
nums = [0,1,2,4,5,7]
result = summaryRanges(nums)

print(result)
    
                
            
        
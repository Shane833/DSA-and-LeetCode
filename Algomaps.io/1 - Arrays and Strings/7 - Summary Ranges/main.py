def summaryRanges(nums):
    # check if the continous difference is one
    i = 0
    j = 0
    c="->"
    result=[]

    while j < len(nums) - 1:
        # If the consecutive difference is not one
        if nums[j] - nums[i] != 1:
            if i == j: # Then either these no.s are the same
                # To check if its the last digit
                if i == len(nums) - 1 or j == len(nums) - 1:
                    # Then we append it to the list
                    result.append(str(nums[j]))
                j += 1
        
        if nums[j] - nums[i] == 1:
            j += 1
            i += 1
            
    print(result)


nums = [0,1,2,4,5,7]
summaryRanges(nums)
            

        
    
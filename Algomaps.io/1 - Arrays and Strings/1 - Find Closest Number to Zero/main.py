# My Solution for LeetCode 2239 - Find Closest Number to Zero

# Ok so the problem is to find the number closest to the zero
# One hint that they have given is that we can take the abs of the value
# and whichever value is the closest to zero (either positive or negative) should be returned

# So how I think I can approach is do a linear run of the array while 
# constantly checking and comparing the constant value and to return it at the end
# However one more thing that I have to keep in mind is to return a number that is BOTH
# closer to zero as well as the largest (so if -1 and 1 are both closest to zero, then we will return 1 as its larger)

# So will I need two variables or can I get it done in ONE??
# Lets try the easy approach with two variables one is our running

# NOTE : I don't need to import math module in order to use the abs function, its built-in

# Approach 1 : Find the smallest and return it
# (Though it got me through one test case this really isn't the right answer)
'''
arr = [2,-1,1]
result = arr[0]
for i in arr:
    if (abs(i) < abs(result)):
        result = i
print(result)
'''

# Approach 2 : Lets sort the array, and then the abs should be least and number should be big
# This seems to work however lets see if I can do it linearly by ommitting the sorting phase
'''
arr = [2,-1,1]
arr.sort()
print(arr)
result = arr[0]
for i in arr:
    if (result < i) and (abs(i) <= abs(result)):
        result = i
print(result)
'''


# Approach 3 : Drop the sorting just apply the logic
# This was pretty good as it worked on 224/227 test cases
# But it failed on the test case with list : [2,1,1,-1,100000]
# where it retured -1 instead of 1
# nums = [-4,-2,1,4,8]
nums = [2,1,1,-1,100000]
result = nums[0]
for i in nums:
    if (abs(i) <= abs(result)):
        result = i
print(result) 

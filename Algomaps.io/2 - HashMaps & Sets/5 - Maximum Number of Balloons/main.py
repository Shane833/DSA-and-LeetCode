# My solution for Leetcode 1189 - Maximum Number of Balloons

count = {'b': 0, 'a': 0, 'l': 0, 'o': 0,'n': 0}

    # generate the count
    for c in text:
        if c in count:
            count[c] += 1
    
    # I need l,o to be 2n and b,a,n to n times for n occurences of balloon
    
    # Try 1
    # for k in count:
    #    if count[k] == 0:
    #        return 0

    # singles = min(count['b'],count['n'],count['a'])
    # doubles = min(count['l'],count['o'])

    # Now I have to convert the values such that n + 2n = 1 occurence
    # if (singles + doubles) % 3 == 0:
    #     return int((singles + doubles) / 3)
    
    # Try 2
    # make a variable for counting the occurences
    # occur = 0

    # for k in count:
    #     # First check if the value is 0 or not
    #     if count[k] <= 0:
    #         return occur
    #     else:
    #         if k == 'b' or k == 'a' or k == 'n':
    #             count[k] -= 1
    #        elif k == 'l' or k == 'o':
    #            # first check if they are greater than 2
    #            # else return the occurences
    #            if count[k] < 2:
    #                return occur
    #            count[k] -= 2
    #        
    #        occur += 1 # increment the occurent

    # Try 3, I need l,o to be 2 and b,a,n to 1 for 1 occurences of balloon
    occur = 0

    while True:
	    # decrement 1 from b, a, and n
	    count['b'] -= 1
	    count['a'] -= 1
	    count['n'] -= 1
	    # decrement 2 from l and o
	    count['l'] -= 2
	    count['o'] -= 2
	    # check if all values are greater than 0
	    for k in count:
	        if count[k] <= 0:
	            return occur
	    # if not then we simply increment the count
	    occur += 1
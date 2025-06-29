# Solution from Algomap.io

def maxNumberofBalloons(text):
	count = defaultdict(int)
	balloon = 'balon'

	for c in text:
	    if c in balloon:
	        count[c] += 1

    # Optimization : if we don't have any occurences of the required letter then we simply return 0
    if any(c not in counter for c in balloon):
    	return 0
    else:
		# // is called integer division and converts the value to an int after division
		return min(count['b'],count['a'],count['n'],count['l']//2,count['o']//2)


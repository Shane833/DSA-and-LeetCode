# My solution for Leetcode 682 - Baseball game

class Solution:
    def calPoints(self, operations: List[str]) -> int:
      stack = []
      total = 0

      for x in operations:
        # Check for each of the operations
        if x == 'C':
            # pop the top element
            total -= stack.pop()
        elif x == 'D':
            d = int(stack[-1]) * 2
            total += d
            stack.append(d)
        elif x == '+':
            add = int(stack[-1]) + int(stack[-2])
            total += add
            stack.append(add)
        else:
            total += int(x)
            stack.append(int(x))
            
    
      # If our stack is not empty at the end we obtain a sum
      #if stack:
        #  for x in stack:
         
         #   total += x
      # An improvement is that I can compute the total alongside
      # The push and pop operations
      return total
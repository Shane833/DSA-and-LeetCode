# Solution from algomap.io
class Solution:
    def calPoints(self, operations: List[str]) -> int:
      stack = []

      for x in operations:
        if x == '+':
            stack.append(stack[-1] + stack[-2])
        elif x == 'D':
            stack.append(stack[-1] * 2)
        elif x == 'C':
            stack.pop()
        else:
            stack.append(int(x))
            
      return sum(stack)
class Solution:
    def isValid(self, s: str) -> bool:
    # First we create a hashmap mapping closing brackets to open brackets
        hashmap = {')' : '(', ']' : '[', '}' : '{'}
        stack = []

        # Now loop through the string and only append open brackets
        for c in s:
            if c not in hashmap: # means its a open bracket
                stack.append(c)
            else:
                # Now check if the stack is empty
                if not stack: # This means that we have too many open brackets
                    return False
                else:
                    # We pop from the stack and check if it is the corresponding bracket
                    popped = stack.pop()
                    if popped != hashmap[c]:
                        return False

        # Again we must make sure that there are no additional brackets left in the stack
        return not stack # If its empty it'll return True else False    
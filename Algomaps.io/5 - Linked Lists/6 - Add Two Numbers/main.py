# Solution #1 for LeetCode 2 - Add Two Numbers


Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        # So we can simply create no. by multiplying by increasing powers of 10
        num1, num2 = 0, 0

        i = 0
        current = l1
        while current != None:  
            num1 += current.val * pow(10,i)
            current = current.next
            i += 1

        i = 0
        current = l2
        while current != None:  
            num2 += current.val * pow(10,i)
            current = current.next
            i += 1
        

        sum = num1 + num2

        if sum == 0:
            return ListNode(val = 0)

        # Now to simply add in reverse order by dividing 
        head = None
        while sum > 0:
            x = sum % 10
            p = ListNode(val = x)
            if head is None:
                head = p
                current = p
            else:
                current.next = p
                current = p
        
            sum //= 10 # Needed to do integer division bcz its not the default
        
        return head



        
        
# Solution from algomap.io

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        # This solution is based on the Floyd algorithm
        # where we move a fast and slow pointer through
        # the list and at some time it is guaranteed that
        # they we will meet, if not then there is no cycle
        dummy = ListNode()
        dummy.next = head
        slow = fast = dummy

        while fast and fast.next: # We don't want to reference none
            fast = fast.next.next # Twice as much
            slow = slow.next # Just one step

            if slow is fast:
                return True
        
        return False


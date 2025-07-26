# My solution for Leetcode 141: Linked List Cycles

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        nodes = []
        cur = head
        
        while cur:
            if nodes:
                if cur.next in nodes:
                    return True
                else:
                    temp = cur
                    cur = cur.next
                    nodes.append(temp)
            else:
                temp = cur
                cur = cur.next
                nodes.append(temp)
        
        return False
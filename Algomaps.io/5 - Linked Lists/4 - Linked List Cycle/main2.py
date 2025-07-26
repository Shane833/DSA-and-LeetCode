# Solution 2 for Leetcode 141: Better runtime performance

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        nodes = {} # I will store the list nodes with their index/pos
        cur = head
        i = 0

        while cur:
            if cur.next in nodes:
                return True
            else:
                nodes[cur] = i
                i = i + 1
                cur = cur.next

        return False
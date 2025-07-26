# My solution for Leetcode 876 - Middle of the Linked List
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        fast = slow = head
        # When the fast pointer has reached the end
        # the slow pointer would have covered half as much
        # distance

        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next

        return slow
        


# solution from algomap.io 

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        d = ListNode() # start with empty list
        cur = d # current iterator in the empty list

        while list1 and list2:
            # Append to the list
            if list1.val < list2.val:
                cur.next = list1
                list1 = list1.next
                cur = cur.next
            else:
                cur.next = list2
                list2 = list2.next
                cur = cur.next
        
        # When the loop ends one or both the list are empty
        # If one of them is not empty then we will append it to 
        # the new list
        cur.next = list1 if list1 else list2

        # since the new list contains an extra node at the beginning
        # we will simply return the next node

        return d.next
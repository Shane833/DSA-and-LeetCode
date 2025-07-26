# My solution of LeetCode 21 - Merge two sorted arrays

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        cur1 = list1 # Points to the List with smaller initial node value could even be empty
        cur2 = list2 # Points to the list with greater initial node value

        result = [] # store the elements here

        while cur1 or cur2:
            if cur1 and cur2:
                # compare and append
                if cur1.val < cur2.val:
                    result.append(cur1.val)
                    cur1 = cur1.next
                else:
                    result.append(cur2.val)
                    cur2 = cur2.next
            elif cur1:
                result.append(cur1.val)
                cur1 = cur1.next
            else:
                result.append(cur2.val)
                cur2 = cur2.next

        list = ListNode(0)
        head = list
        for i in result:
            head.next = ListNode(i)
            head = head.next
        
        if(list):
            list = list.next
        
        return list
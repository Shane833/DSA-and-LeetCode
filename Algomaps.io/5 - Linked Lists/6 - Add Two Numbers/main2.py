# trying another solution

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        # Another thing I can try is to loop over both lists
        # until both are exhausted and maintain a sum and a carry
        # If the carry is not zero but the sum is zero then we
        # should create a new node regardless to store that carry

        cur1 = l1
        cur2 = l2
        val = 0
        carry = 0

        while cur1 or cur2:
            x = cur1.val if cur1 else 0
            y = cur2.val if cur2 else 0

            sum = x + y

            val = sum % 10

            if val or carry:
                p = ListNode
                if head is None:
                    p 

            carry = sum // 10 # Compute the carry to be added later
                              # i.e. will be added in the next 

            print(f"Val : {val} & carry : {carry}")

            cur1 = cur1.next if cur1 else None
            cur2 = cur2.next if cur2 else None
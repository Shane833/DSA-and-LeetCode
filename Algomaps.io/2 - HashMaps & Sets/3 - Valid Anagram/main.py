# This is my solution for LeetCode 242
from collections import defaultdict

def isAnagram(self, s: str, t: str) -> bool:
    # The important thing is that if
    # t is really an anagram then
    # the size of the strings should be equal to begin with

    if len(t) != len(s): 
        return False
    
    # Creating counters
    s_dict = defaultdict(int)
    t_dict = defaultdict(int)

    for c in s:
        s_dict[c] += 1
    
    for c in t:
        t_dict[c] += 1
    
    # Now I can check if the count of each variable is same or not
    for x in s_dict:
        if s_dict[x] != t_dict[x]:
            return False

    return True
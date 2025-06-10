# LEETCODE 383

# This is my solution
def canConstruct(ransomNote, magazine):
    # This problem revolves around the availability of the alphabets including their size
    r_dict = {}
    m_dict = {}

    # Creating counters for the numbers
    for s in ransomNote:
        if s in r_dict:
            r_dict[s] += 1
        else:
            r_dict[s] = 1
    
    for s in magazine:
        if s in m_dict:
            m_dict[s] += 1
        else:
            m_dict[s] = 1

    for x in r_dict:
        if x not in m_dict:
            return False
        else:
            if r_dict[x] > m_dict[x]:
                return False

    return True
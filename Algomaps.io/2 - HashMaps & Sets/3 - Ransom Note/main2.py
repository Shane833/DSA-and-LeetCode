    # This problem revolves around the availability of the alphabets including their size
        m_dict = {}

        # Creating counters for the numbers   
        for s in magazine:
            if s in m_dict:
                m_dict[s] += 1
            else:
                m_dict[s] = 1

        for x in ransomNote:
            if x not in m_dict:
                return False
            else:
                if m_dict[x] == 0:
                    return False
                m_dict[x] -= 1
        
        return True
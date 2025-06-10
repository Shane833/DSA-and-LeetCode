def canConstruct(self, ransomNote: str, magazine: str) -> bool:
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
            elif m_dict[x] == 1:
                del m_dict[x]
            else:
                m_dict[x] -= 1
        
        return True
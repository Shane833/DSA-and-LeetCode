# Solution from algomap.io

class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        merged = []
        i = j = 0
        I = len(word1)
        J = len(word2)

        while len(merged) != len(word1) + len(word2):
            if i < I:
                merged.append(word1[i])
                i += 1
            if j < J:
                merged.append(word2[j])
                j += 1

        return ''.join(merged)

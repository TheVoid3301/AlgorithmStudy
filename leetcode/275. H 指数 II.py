class Solution:
    def hIndex(self, citations: List[int]) -> int:
        if len(citations) == 1:
            return 1 if citations[0] > 0 else 0
        for i in range(len(citations), 0, -1):
            if citations[len(citations) - i] >= i:
                return i
        return 0
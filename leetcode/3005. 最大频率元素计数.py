class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
        m = dict()
        for n in nums:
            m[n] = m.get(n, 0) + 1
        maxCount = 0
        res = 0
        for k, v in m.items():
            if v > maxCount:
                maxCount = v
        for k, v in m.items():
            if v == maxCount:
                res += maxCount

        return res

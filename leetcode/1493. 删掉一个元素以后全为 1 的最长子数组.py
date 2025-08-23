class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        pre = [0] * n
        suf = [0] * n
        pre[0] = nums[0]
        for i in range(1, n):
            pre[i] = pre[i - 1] + 1 if nums[i] else 0
        suf[-1] = nums[-1]
        for i in range(n - 2, -1, -1):
            suf[i] = suf[i + 1] + 1 if nums[i] else 0

        ans = 0
        for i in range(n):
            pre_sum = pre[i - 1] if i > 0 else 0
            suf_sum = suf[i + 1] if i < n - 1 else 0
            ans = max(ans, pre_sum + suf_sum)

        return ans
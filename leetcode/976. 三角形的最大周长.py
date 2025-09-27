class Solution:
    def largestPerimeter(self, nums: List[int]) -> int:
        nums.sort()
        for i in range(1, len(nums) - 1):
            if nums[-i] < nums[-i - 1] + nums[-i - 2]:
                return nums[-i] + nums[-i - 1] + nums[-i - 2]
        return 0
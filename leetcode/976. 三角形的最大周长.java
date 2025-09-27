class Solution {
    public int largestPerimeter(int[] nums) {
        Arrays.sort(nums);
        for (int i = 1; i <= nums.length - 2; i++) {
            if (nums[nums.length - i] < nums[nums.length - i - 1] + nums[nums.length - i - 2]) {
                return nums[nums.length - i] + nums[nums.length - i - 1] + nums[nums.length - i - 2];
            }
        }
        return 0;
    }
}
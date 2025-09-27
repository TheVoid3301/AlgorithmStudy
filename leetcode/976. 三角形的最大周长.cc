class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i <= nums.size() - 2; ++i) {
            if (nums[nums.size() - i] < nums[nums.size() - i - 1] + nums[nums.size() - i - 2]) {
                return nums[nums.size() - i] + nums[nums.size() - i - 1] + nums[nums.size() - i - 2];
            }
        }
        return 0;
    }
};
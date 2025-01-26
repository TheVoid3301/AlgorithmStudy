class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size(), total = 0, left = 0;
        for (int i = 0; i < nums.size(); ++i) {
            total += nums[i];
        }
        vector<int> res(nums.size() - 1, 0);
        for (int i = 0; i < nums.size() - 1; ++i) {
            left += nums[i];
            total -= nums[i];
            res[i] = left - total;
        }
        int co = 0;
        for (auto i : res) {
            if (i % 2 == 0) {
                co++;
            }
        }
        return co;
    }
};
/*
 * @lc app=leetcode.cn id=2294 lang=cpp
 *
 * [2294] 划分数组使最大差为 K
 */

// @lc code=start
class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int res = 0;
        int i = 1;
        int s = nums[0];
        for (i; i < nums.size(); ++i) {
            if (nums[i] - s <= k) {
                continue;
            } else {
                res++;
                s = nums[i];
            }
        }
        if (i == nums.size()) {
            res++;
        }
        return res;
    }
};
// @lc code=end


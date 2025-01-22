/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res(nums.size(), 1);
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (nums[i] > nums[j])
                {
                    res[i] = max(res[i], res[j] + 1);
                }
            }
        }
        int r = 0;
        for (auto i : res)
        {
            if (r < i)
            {
                r = i;
            }
        }
        return r;
    }
};
// @lc code=end


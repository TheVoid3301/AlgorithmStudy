/*
 * @lc app=leetcode.cn id=2799 lang=cpp
 *
 * [2799] 统计完全子数组的数目
 */

// @lc code=start
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));
        set<int> s;
        for (int i = 0; i < nums.size(); ++i) {
            s.insert(nums[i]);
        }
        int count = s.size();
        for (int i = 0; i < nums.size(); ++i) {
            s.clear();
            for (int j = i; j < nums.size(); ++j) {
                if (i == j) {
                    dp[i][j] = 1;
                    s.insert(nums[j]);
                    continue;
                }
                if (s.count(nums[j])) {
                    dp[i][j] = dp[i][j - 1];
                } else {
                    s.insert(nums[j]);
                    dp[i][j] = dp[i][j - 1] + 1;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i; j < nums.size(); ++j) {
                if (dp[i][j] == count) {
                    res++;
                }
            }
        }
        return res;
    }
};
// @lc code=end


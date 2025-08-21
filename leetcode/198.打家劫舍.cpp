/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty())
        {
            return 0;
        }
        int size = nums.size();
        if(size == 1)
        {
            return nums[0];
        }
        vector<int> dp(size, 0);
        dp[0] = nums[0];//只有一间房间则偷取这一间
        dp[1] = max(nums[0], nums[1]);//只有两件房间则偷取金额大的那一间
        for(int i = 2; i < size; ++i)
        {
            // 对于第i间房间，如果偷取该房间那么就不能偷取i-1间房，则金额为i-2间房+i间房
            // 若不偷取则金额为i-1间房的金额（dp[i]记录的是不论第i间房间偷不偷当到第i间房是已经偷取的最大金额）
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[size - 1];
    }
};
// @lc code=end


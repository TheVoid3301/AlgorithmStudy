/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> res(nums.size(), INT_MAX);
        for(int i = 0; i <= nums[0]; ++i)
        {
            if(i <= (nums.size() - 1))
            {
                res[i] = 1;
            }
        }
        res[0] = 0;
        for(int i = 1; i < nums.size(); ++i)
        {
            for(int j = 1; j <= nums[i]; ++j)
            {
                if((i + j) <= ( nums.size() - 1))
                {
                    res[i + j] = min(res[i] + 1, res[i + j]);
                }
            }
        }
        return res[nums.size() - 1];
    }
};
// @lc code=end


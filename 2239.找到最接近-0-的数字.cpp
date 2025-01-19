/*
 * @lc app=leetcode.cn id=2239 lang=cpp
 *
 * [2239] 找到最接近 0 的数字
 */

// @lc code=start
class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int res = INT_MAX;
        for(int i : nums)
        {
            if(abs(res) > abs(i))
            {
                res = i;
            }
            if(abs(res) == abs(i))
            {
                res = max(res, i);
            }
        }
        return res;
    }
};
// @lc code=end


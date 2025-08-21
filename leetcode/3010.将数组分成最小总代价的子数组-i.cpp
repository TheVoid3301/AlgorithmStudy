/*
 * @lc app=leetcode.cn id=3010 lang=cpp
 *
 * [3010] 将数组分成最小总代价的子数组 I
 */

// @lc code=start
class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int res = nums[0];
        int less1 = INT_MAX, less2 = INT_MAX, p;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < less1) {
                less1 = nums[i];
                p = i;
            }
        }
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < less2 && i != p) {
                less2 = nums[i];
            }
        }
        return res + less1 + less2;
    }
};
// @lc code=end


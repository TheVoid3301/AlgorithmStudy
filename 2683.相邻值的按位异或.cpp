/*
 * @lc app=leetcode.cn id=2683 lang=cpp
 *
 * [2683] 相邻值的按位异或
 */

// @lc code=start
class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int xor_ = 0;
        for (int x : derived) {
            xor_ ^= x;
        }
        return xor_ == 0;
    }
};
// @lc code=end


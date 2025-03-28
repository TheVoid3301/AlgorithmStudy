/*
 * @lc app=leetcode.cn id=2716 lang=cpp
 *
 * [2716] 最小化字符串长度
 */

// @lc code=start
class Solution {
public:
    int minimizedStringLength(string s) {
        int mask = 0;
        for (char c : s) {
            mask |= 1 << (c - 'a');
        }
        return __builtin_popcount(mask);
    }
};
// @lc code=end


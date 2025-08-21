/*
 * @lc app=leetcode.cn id=3110 lang=cpp
 *
 * [3110] 字符串的分数
 */

// @lc code=start
class Solution {
public:
    int scoreOfString(string s) {
        int res = 0;
        for (int i = 0; i < s.size() - 1; ++i) {
            res += abs(s[i] - s[i + 1]);
        }
        return res;
    }
};
// @lc code=end


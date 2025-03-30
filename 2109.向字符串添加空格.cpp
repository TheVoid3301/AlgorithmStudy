/*
 * @lc app=leetcode.cn id=2109 lang=cpp
 *
 * [2109] 向字符串添加空格
 */

// @lc code=start
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int i = 0, j = 0;
        string res = "";
        while (i < spaces.size() && j < s.size()) {
            if (j == spaces[i]) {
                res += " ";
                res += s[j];
                ++i;
                ++j;
            } else {
                res += s[j];
                ++j;
            }
        }
        while (j < s.size()) {
            res += s[j];
            ++j;
        }
        return res;
    }
};
// @lc code=end


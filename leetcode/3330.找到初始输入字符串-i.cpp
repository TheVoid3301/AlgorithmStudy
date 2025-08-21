/*
 * @lc app=leetcode.cn id=3330 lang=cpp
 *
 * [3330] 找到初始输入字符串 I
 */

// @lc code=start
class Solution {
public:
    int possibleStringCount(string word) {
        int i = 0;
        int res = 0;
        while (i < word.size()) {
            int t = 0;
            int k;
            for (k = i + 1; k < word.size(); ++k) {
                if (word[k] != word[i]) {
                    if (t != 0) {
                        res += t;
                    }
                    i = k;
                    break;
                } else {
                    ++t;
                }
            }
            if (k == word.size()) {
                if (t != 0) {
                    res += t;
                }
                break;
            }
        }
        return res + 1;
    }
};
// @lc code=end


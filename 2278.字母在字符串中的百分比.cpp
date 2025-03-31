/*
 * @lc app=leetcode.cn id=2278 lang=cpp
 *
 * [2278] 字母在字符串中的百分比
 */

// @lc code=start
class Solution {
public:
    int percentageLetter(string s, char letter) {
        map<char, int> m;
        for (int i = 0; i < s.size(); ++i) {
            if (m.count(s[i])) {
                m[s[i]]++;
            } else {
                m[s[i]] = 1;
            }
        }
        return (int)((double)(m[letter]) / s.size() * 100);
    }
};
// @lc code=end


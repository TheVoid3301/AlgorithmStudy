/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
class Solution {
public:
    bool check(string &s) {
        for (int i = 0; i < s.size() / 2; ++i) {
            if (s[i] != s[s.size() - i - 1]) {
                return false;
            }
        }
        return true;
    }
    bool isPalindrome(string s) {
        string res = "";
        for (int i = 0; i < s.size(); ++i) {
            if (isalpha(s[i])) {
                if (isupper(s[i])) {
                    res += tolower(s[i]);
                } else {
                    res += s[i];
                }
            } else if (isdigit(s[i])) {
                res += s[i];
            }
        }
        return check(res);
    }
};
// @lc code=end


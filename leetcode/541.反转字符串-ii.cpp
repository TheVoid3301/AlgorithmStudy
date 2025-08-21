/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */

// @lc code=start
class Solution {
public:
    void strReserve(string &s) {
        for (int i = 0; i < s.size() / 2; ++i) {
            swap(s[i], s[s.size() - i - 1]);
        }
    }
    string reverseStr(string s, int k) {
        string res;
        bool f = true;
        for (int i = 0; i < s.size(); i += k) {
            string l = s.substr(i, k);
            if (f) {
                strReserve(l);
            }
            f = !f;
            res += l;
        }
        return res;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution {
public:
    bool checkhui(string s) {
        for (int i = 0; i < s.size() / 2; ++i) {
            if (s[i] != s[s.size() - 1 - i]) {
                return false;
            }
        }
        return true;
    }
    void huisu(string &s, int start, vector<vector<string>> &res, vector<string> &p) {
        if (start >= s.size()) {
            res.push_back(p);
            return ;
        }
        for (int i = 1; i <= s.size() - start; ++i) {
            if (checkhui(s.substr(start, i))) {
                p.push_back(s.substr(start, i));
                huisu(s, start + i, res, p);
                p.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> p;
        huisu(s, 0, res, p);
        return res;
    }
};
// @lc code=end


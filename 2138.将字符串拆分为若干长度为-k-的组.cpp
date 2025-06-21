/*
 * @lc app=leetcode.cn id=2138 lang=cpp
 *
 * [2138] 将字符串拆分为若干长度为 k 的组
 */

// @lc code=start
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int start = 0;
        vector<string> res;
        while (start + k < s.size()) {
            string t = s.substr(start, k);
            res.push_back(t);
            start += k;
        }
        if (start < s.size()) {
            string t = s.substr(start);
            while (t.size() < k) {
                t += fill;
            }
            res.push_back(t);
        }
        return res;
    }
};
// @lc code=end


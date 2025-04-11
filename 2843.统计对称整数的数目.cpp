/*
 * @lc app=leetcode.cn id=2843 lang=cpp
 *
 * [2843] 统计对称整数的数目
 */

// @lc code=start
class Solution {
public:
    bool check(string &s) {
        int l = 0, r = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (i < s.size() / 2) {
                l += (s[i] - '0');
            } else {
                r += (s[i] - '0');
            }
        }
        return l == r;
    }

    int countSymmetricIntegers(int low, int high) {
        vector<string> res;
        for (int i = low; i <= high; ++i) {
            string s = to_string(i);
            if (s.size() % 2 == 0) {
                res.push_back(i);
            }
        }
        int count = 0;
        for (auto s : res) {
            if (check(s)) {
                count++;
            }
        }
        return count;
    }
};
// @lc code=end


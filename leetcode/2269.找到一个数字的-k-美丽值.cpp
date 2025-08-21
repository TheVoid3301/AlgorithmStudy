/*
 * @lc app=leetcode.cn id=2269 lang=cpp
 *
 * [2269] 找到一个数字的 K 美丽值
 */

// @lc code=start
class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int res = 0;
        string s = to_string(num);
        for (int i = 0; i < s.size() - k + 1; i++) {
            int x = stoi(s.substr(i, k));
            if (x != 0 && num % x == 0)
                res ++;
        }
        return res;
    }
};
// @lc code=end


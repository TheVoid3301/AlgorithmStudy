/*
 * @lc app=leetcode.cn id=2894 lang=cpp
 *
 * [2894] 分类求和并作差
 */

// @lc code=start
class Solution {
public:
    int differenceOfSums(int n, int m) {
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            if (i % m != 0) {
                res += i;
            } else {
                res -= i;
            }
        }
        return res;
    }
};
// @lc code=end


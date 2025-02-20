/*
 * @lc app=leetcode.cn id=2527 lang=cpp
 *
 * [2527] 查询数组异或美丽值
 */

// @lc code=start
class Solution {
public:
    vector<int> evenOddBit(int n) {
        bool f = true;
        int even = 0, odd = 0;
        while (n > 0) {
            if (n % 2 == 1 && f) {
                even++;
            } else if (n % 2 == 1 && !f) {
                odd++;
            }
            n = n / 2;
            f = !f;
        }
        return {even, odd};
    }
};
// @lc code=end


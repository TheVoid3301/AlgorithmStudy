/*
 * @lc app=leetcode.cn id=342 lang=cpp
 *
 * [342] 4的幂
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfFour(int n) {
        while (n > 0) {
            if (n == 1) {
                return true;
            }
            if (n % 4 != 0) {
                return false;
            }
            n /= 4;
        }
        return false;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=326 lang=cpp
 *
 * [326] 3 的幂
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfThree(int n) {
        while (n) {
            if (n == 1) return true;
            if (n % 3 != 0) return false;
            n /= 3;
        }
        return false;
    }
};
// @lc code=end


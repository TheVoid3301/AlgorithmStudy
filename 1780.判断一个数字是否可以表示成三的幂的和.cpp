/*
 * @lc app=leetcode.cn id=1780 lang=cpp
 *
 * [1780] 判断一个数字是否可以表示成三的幂的和
 */

// @lc code=start
class Solution {
public:
    bool checkPowersOfThree(int n) {
        while (n) {
            if (n % 3 == 2) {
                return false; // 如果余数为2，无法表示成三的幂的和
            }
            n /= 3; // 除以3，继续检查下一个数字
        }
        return true;
    }
};
// @lc code=end


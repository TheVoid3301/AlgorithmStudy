/*
 * @lc app=leetcode.cn id=1550 lang=cpp
 *
 * [1550] 存在连续三个奇数的数组
 */

// @lc code=start
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        if (arr.size() < 3) {
            return false;
        }
        for (int i = 0; i <= arr.size() - 3; ++i) {
            if (arr[i] % 2 == 1) {
                int j = i + 1;
                for (j; j <= i + 2; ++j) {
                    if (arr[j] % 2 == 0) {
                        break;
                    }
                }
                if (j == i + 3) {
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=2145 lang=cpp
 *
 * [2145] 统计隐藏数组数目
 */

// @lc code=start
class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int x = 0, y = 0, cur = 0;
        for (int d: differences) {
            cur += d;
            x = min(x, cur);
            y = max(y, cur);
            if (y - x > upper - lower) {
                return 0;
            }
        }
        return (upper - lower) - (y - x) + 1;
    }
};
// @lc code=end


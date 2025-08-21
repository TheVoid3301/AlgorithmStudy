/*
 * @lc app=leetcode.cn id=598 lang=cpp
 *
 * [598] 区间加法 II
 */

// @lc code=start
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int minx = m, miny = n;
        for (auto i : ops) {
            minx = min(minx, i[0]);
            miny = min(miny, i[1]);
        }
        return minx * miny;
    }
};
// @lc code=end


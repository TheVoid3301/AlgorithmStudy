/*
 * @lc app=leetcode.cn id=3195 lang=cpp
 *
 * [3195] 包含所有 1 的最小矩形面积 I
 */

// @lc code=start
class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int r1 = grid[0].size(), r2 = -1, d1 = grid.size(), d2 = -1;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    r1 = min(r1, j);
                    d1 = min(d1, i);
                    r2 = max(r2, j);
                    d2 = max(d2, i);
                }
            }
        }
        return (r2 - r1 + 1) * (d2 - d1 + 1);
    }
};
// @lc code=end


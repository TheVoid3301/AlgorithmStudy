/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> res(grid.size(), vector<int>(grid[0].size(), INT_MAX));
        res[0][0] = grid[0][0];
        for(int i = 1; i < grid[0].size(); ++i)
        {
            res[0][i] = res[0][i - 1] + grid[0][i];
        }
        for(int i = 1; i < grid.size(); ++i)
        {
            res[i][0] = res[i - 1][0] + grid[i][0];
        }
        for(int i = 1; i < grid.size(); ++i)
        {
            for(int j = 1; j < grid[0].size(); ++j)
            {
                res[i][j] = min(res[i - 1][j] + grid[i][j], res[i][j - 1] + grid[i][j]);
            }
        }
        return res[grid.size() - 1][grid[0].size() - 1];
    }
};
// @lc code=end


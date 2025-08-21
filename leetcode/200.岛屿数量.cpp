/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
public:
    int dfs(int i, int j, vector<vector<char>>& grid) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '1') {
            return 0;
        }
        grid[i][j] = '0'; // 标记为已访问
        dfs(i - 1, j, grid); // 上
        dfs(i + 1, j, grid); // 下
        dfs(i, j - 1, grid); // 左
        dfs(i, j + 1, grid); // 右
        return 1;
    }

    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        int row = grid.size();
        if (row == 0) return 0;
        int col = grid[0].size();

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == '1') {
                    dfs(i, j, grid);
                    res++;
                }
            }
        }
        return res;
    }
};
// @lc code=end


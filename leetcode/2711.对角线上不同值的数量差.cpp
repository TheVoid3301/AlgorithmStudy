/*
 * @lc app=leetcode.cn id=2711 lang=cpp
 *
 * [2711] 对角线上不同值的数量差
 */

// @lc code=start
class Solution {
public:
    int culculate(int i, int j, vector<vector<int>>& grid) {
        set<int> count;
        int x = i - 1, y = j - 1, sum = 0;
        while (x >= 0 && y >= 0) {
            count.insert(grid[x][y]);
            x--;
            y--;
        }
        sum += count.size();
        count.clear();
        x = i + 1;
        y = j + 1;
        while (x < grid.size() && y < grid[0].size()) {
            count.insert(grid[x][y]);
            x++;
            y++;
        }
        sum -= count.size();
        return abs(sum);
    }
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        vector<vector<int>> res(grid.size(), vector<int>(grid[0].size()));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); ++j) {
                res[i][j] = culculate(i, j, grid);
            }
        }
        return res;
    }
};
// @lc code=end


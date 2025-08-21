/*
 * @lc app=leetcode.cn id=1706 lang=cpp
 *
 * [1706] 球会落何处
 */

// @lc code=start
class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> res(grid[0].size(), -1);
        int f = 0;
        for (int i = 0; i < grid[0].size(); ++i) {
            int t = i;
            for (int j = 0; j <= grid.size(); ++j) {
                if (t < 0 || t >= grid[0].size()) {
                    res[i] = -1;
                    break;
                }
                if (j == grid.size()) {
                    res[i] = t;
                    break;
                }
                if (t + 1 < grid[0].size()) {
                    if (grid[j][t] == 1 && grid[j][t + 1] == -1) {
                        res[i] = -1;
                        break;
                    }
                }
                if (t - 1 >= 0) {
                    if (grid[j][t] == -1 && grid[j][t - 1] == 1) {
                        res[i] = -1;
                        break;
                    }
                }
                if (grid[j][t] == 1) {
                    f = 1;
                }
                if (grid[j][t] == -1) {
                    f = -1;
                }
                t += f;
            }
        }
        return res;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> res(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));
        for (int i = 0; i < obstacleGrid.size(); ++i)
        {
            if (obstacleGrid[i][0] == 1)
            {
                break;
            }
            res[i][0] = 1;
        }
        for (int i = 0; i < obstacleGrid[0].size(); ++i)
        {
            if (obstacleGrid[0][i] == 1)
            {
                break;
            }
            res[0][i] = 1;
        }
        for (int i = 1; i < obstacleGrid.size(); ++i)
        {
            for (int j = 1; j < obstacleGrid[0].size(); ++j)
            {
                if (obstacleGrid[i][j] == 1)
                {
                    continue;
                }
                res[i][j] = res[i - 1][j] + res[i][j - 1];
            }
        }
        return res[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
    }
};
// @lc code=end


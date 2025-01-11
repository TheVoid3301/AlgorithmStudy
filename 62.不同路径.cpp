/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> res(m, vector<int>(n, 1));
        if(m > 1 && n > 1)
        {
            res[1][0] = 1;
            res[0][1] = 1;
        }
        else if(m == 1 && n != 1)
        {
            res[0][1] = 1;
        }
        else if(n == 1 && m != 1)
        {
            res[1][0] = 1;
        }
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(i - 1 >= 0 && j - 1 >= 0)
                {
                    res[i][j] = res[i - 1][j] + res[i][j - 1];
                }
                else if(i - 1 >= 0 && j - 1 < 0)
                {
                    res[i][j] = max(res[i - 1][j], res[i][j]);
                }
                else if(i - 1 < 0 && j - 1 >= 0)
                {
                    res[i][j] = max(res[i][j - 1], res[i][j]);
                }
            }
        }
        return res[m - 1][n - 1];
    }
};
// @lc code=end


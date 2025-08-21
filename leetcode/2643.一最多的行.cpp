/*
 * @lc app=leetcode.cn id=2643 lang=cpp
 *
 * [2643] 一最多的行
 */

// @lc code=start
class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int row = 0, res = 0;
        for (int i = 0; i < mat.size(); ++i)
        {
            int t = 0;
            for (int j = 0; j < mat[i].size(); ++j)
            {
                if (mat[i][j] == 1)
                {
                    ++t;
                }
            }
            if (t > res)
            {
                row = i;
                res = t;
            }
        }
        return {row, res};
    }
};
// @lc code=end


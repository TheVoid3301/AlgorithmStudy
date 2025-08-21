/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // 先转置矩阵再逆序(按行或者列逆序都可以)
        int n = matrix.size();
        for(int i = 0; i < n; ++i)
        {
            for(int j = i; j < n; ++j)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n / 2; ++j)
            {
                swap(matrix[i][j], matrix[i][n - j - 1]);
            }
        }
    }
};
// @lc code=end


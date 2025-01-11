/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int x = 0, y = n - 1;
        // 将原看作一个从原矩阵左下角到x,y的新矩阵
        while (x < m && y >= 0) {
            if (matrix[x][y] == target) {
                return true;
            }
            if (matrix[x][y] > target) {
                // 因为每列都是递增的，所以当matrix[x][y] > target时，说明这列的最小值都大于target，所以缩小列的范围
                --y;
            }
            else {
                // 因为每行都是递增的，所以当matrix[x][y] < targe时，说明这行的最大值都小于target，所以缩小行的范围
                ++x;
            }
        }
        return false;
    }
};
// @lc code=end


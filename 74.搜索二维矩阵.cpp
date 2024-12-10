/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int t = -1;
        for(int i = 0; i < matrix.size(); ++i)
        {
            if (matrix[i][0] <= target && matrix[i][matrix[0].size() - 1] >= target)
            {
                t = i;
                break;
            }
        }
        if(t == -1)
        {
            return false;
        }
        int start = 0, end = matrix[0].size();
        while(start <= end)
        {
            int temp = matrix[t][(start + end) / 2];
            if(target > temp)
            {
                start = (start + end) / 2 + 1;
            }
            else if(target < temp)
            {
                end = (start + end) / 2 - 1;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end


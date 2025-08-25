/*
 * @lc app=leetcode.cn id=3000 lang=cpp
 *
 * [3000] 对角线最长的矩形的面积
 */

// @lc code=start
class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int max_len = 0;
        int max_area = 0;
        for (auto &i : dimensions) {
            if (i[0] * i[0] + i[1] * i[1] > max_len) {
                max_len = i[0] * i[0] + i[1] * i[1];
                max_area = i[0] * i[1];
            } else if (i[0] * i[0] + i[1] * i[1] == max_len) {
                max_area = max(max_area, i[0] * i[1]);
            }
        }
        return max_area;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 */

// @lc code=start
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> res;
        res.push_back({1});
        res.push_back({1, 1});
        if (rowIndex <= 1) {
            return res[rowIndex];
        }
        for (int i = 2; i <= rowIndex; ++i) {
            vector<int> p;
            p.push_back(1);
            for (int j = 1; j <= i - 1; ++j) {
                p.push_back(res[i - 1][j - 1] + res[i - 1][j]);
            }
            p.push_back(1);
            res.push_back(p);
        }
        return res[rowIndex];
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution {
public:
    void backTracking(int &n, vector<vector<int>> &visited, vector<vector<string>> &res, vector<string> &p, int row) {
        if (row == n) {
            res.push_back(p);
            return ;
        }
        for (int i = 0; i < n; ++i) {
            if (visited[row][i] == 0) {
                for (int j = row; j < n; ++j) {
                    visited[j][i]++;
                }
                for (int r = row + 1, c = i + 1; r < n && c < n; ++r, ++c) {
                    visited[r][c]++;
                }
                for (int r = row + 1, c = i - 1; r < n && c >= 0; ++r, --c) {
                    visited[r][c]++;
                }
                p[row][i] = 'Q';
                backTracking(n, visited, res, p, row + 1);
                p[row][i] = '.';
                for (int j = row; j < n; ++j) {
                    visited[j][i]--;
                }
                for (int r = row + 1, c = i + 1; r < n && c < n; ++r, ++c) {
                    visited[r][c]--;
                }
                for (int r = row + 1, c = i - 1; r < n && c >= 0; ++r, --c) {
                    visited[r][c]--;
                }
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<vector<int>> visited(n, vector<int>(n, 0));
        string s(n, '.');
        vector<string> p(n, s);
        backTracking(n, visited, res, p, 0);
        return res;
    }
};
// @lc code=end


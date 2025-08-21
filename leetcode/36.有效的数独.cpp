/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<char> resRow, resCol, resTan;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.' && resRow.count(board[i][j])) {
                    return false;
                }
                resRow.insert(board[i][j]);
            }
            resRow.clear();
        }
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[j][i] != '.' && resCol.count(board[j][i])) {
                    return false;
                }
                resCol.insert(board[j][i]);
            }
            resCol.clear();
        }
        for (int i = 0; i < 9; i += 3) {
            for (int j = i; j < i + 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    if (board[j][k] != '.' && resTan.count(board[j][k])) {
                        return false;
                    }
                    resTan.insert(board[j][k]);
                }
            }
            resTan.clear();
            for (int j = i; j < i + 3; ++j) {
                for (int k = 3; k < 6; ++k) {
                    if (board[j][k] != '.' && resTan.count(board[j][k])) {
                        return false;
                    }
                    resTan.insert(board[j][k]);
                }
            }
            resTan.clear();
            for (int j = i; j < i + 3; ++j) {
                for (int k = 6; k < 9; ++k) {
                    if (board[j][k] != '.' && resTan.count(board[j][k])) {
                        return false;
                    }
                    resTan.insert(board[j][k]);
                }
            }
            resTan.clear();
        }
        return true;
    }
};
// @lc code=end


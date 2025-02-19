/*
 * @lc app=leetcode.cn id=289 lang=cpp
 *
 * [289] 生命游戏
 */

// @lc code=start
class Solution {
private:
    int a[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}};
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> res(board.size(), vector<int>(board[0].size(), 0));
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                int cou = 0;
                for (int k = 0; k < 8; ++k) {
                    int nx = i + a[k][0];
                    int ny = j + a[k][1];
                    if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size()) {
                        if (board[nx][ny] == 1) {
                            cou++;
                        }
                    }
                }
                if (board[i][j] == 0 && cou == 3) {
                    res[i][j] = 1;
                } else if (board[i][j] == 1 && cou >= 2 && cou <= 3) {
                    res[i][j] = 1;
                }
            }
        }
        board = res;
    }
};
// @lc code=end


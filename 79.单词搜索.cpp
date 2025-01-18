/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution {
public:
    int a[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool dfs(vector<vector<char>>& board, vector<vector<int>>& visited, int x, int y, string& word, int p)
    {
        if(board[x][y] != word[p])
        {
            return false;
        }
        else if(board[x][y] == word[p] && p == word.length() - 1)
        {
            return true;
        }
        visited[x][y] = 1;
        bool result = false;
        for(int i = 0; i < 4; ++i)
        {
            int nx = x + a[i][0], ny = y + a[i][1];
            if(nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size() && visited[nx][ny] == 0)
            {
                bool flag = dfs(board, visited, nx, ny, word, p + 1);
                if(flag)
                {
                    result = true;
                    break;
                }
            }
        }
        visited[x][y] = 0;
        return result;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> visited(board.size(), vector<int>(board[0].size(), 0));
        for(int i = 0; i < board.size(); ++i)
        {
            for(int j = 0; j < board[0].size(); ++j)
            {
                if(dfs(board, visited, i, j, word, 0))
                {
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end


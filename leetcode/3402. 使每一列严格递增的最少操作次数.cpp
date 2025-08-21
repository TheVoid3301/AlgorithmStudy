class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int res = 0;
        for (int i = 0; i < grid[0].size(); ++i) {
            for (int j = 0; j < grid.size() - 1; ++j) {
                if (grid[j + 1][i] <= grid[j][i]) {
                    res += (grid[j][i] - grid[j + 1][i] + 1);
                    grid[j + 1][i] = grid[j + 1][i] + (grid[j][i] - grid[j + 1][i] + 1);
                }
            }
        }
        return res;
    }
};
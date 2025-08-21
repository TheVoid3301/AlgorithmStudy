/*
 * @lc app=leetcode.cn id=624 lang=cpp
 *
 * [624] 数组列表中的最大距离
 */

// @lc code=start
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int minn = INT_MAX, maxn = INT_MIN, f = 0;
        vector<bool> visited(arrays.size(), false);
        for (int i = 0; i < arrays.size(); ++i) {
            if (arrays[i][0] < minn) {
                minn = arrays[i][0];
               f = i;
            }
        }
        visited[f] = true;
        for (int i = 0; i < arrays.size(); ++i) {
            if (arrays[i][arrays[i].size() - 1] > maxn && !visited[i]) {
                maxn = arrays[i][arrays[i].size() - 1];
            }
        }
        int res = maxn - minn;
        minn = INT_MAX;
        maxn = INT_MIN;
        f = 0;
        fill(visited.begin(), visited.end(), false);
        for (int i = 0; i < arrays.size(); ++i) {
            if (arrays[i][arrays[i].size() - 1] > maxn) {
                maxn = arrays[i][arrays[i].size() - 1];
                f = i;
            }
        }
        visited[f] = true;
        for (int i = 0; i < arrays.size(); ++i) {
            if (arrays[i][0] < minn && !visited[i]) {
                minn = arrays[i][0];
            }
        }
        res = max(maxn - minn, res);
        return res;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=1751 lang=cpp
 *
 * [1751] 最多可以参加的会议数目 II
 */

// @lc code=start
class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        vector<vector<int>> dp(n + 1,vector<int>(k + 1));
        ranges::sort(events, [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        for (int i = 0; i < n; i++) {
            int p = ranges::lower_bound(events, events[i][0], {}, [](const auto& e) {             
                return e[1]; 
            }) - events.begin();
            for (int j = 1; j <= k; j++) {
                dp[i + 1][j] = max(dp[i][j], dp[p][j - 1] + events[i][2]);
            }
        }

        return dp[n][k];
    }
};
// @lc code=end


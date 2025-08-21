/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> res(prices.size(), 0);
        int maxn = 0;
        for (int i = 1; i < prices.size(); ++i) {
            res[i] = max(max(0, res[i - 1] - prices[i - 1] + prices[i]), prices[i] - prices[i - 1]);
            maxn = max(maxn, res[i]);
        }
        return maxn;
    }
};
// @lc code=end


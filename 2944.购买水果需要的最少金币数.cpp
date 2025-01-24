/*
 * @lc app=leetcode.cn id=2944 lang=cpp
 *
 * [2944] 购买水果需要的最少金币数
 */

// @lc code=start
class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        unordered_map<int, int> memo;

        function<int(int)> dp = [&](int index) -> int 
        {
            // 如果免费的范围大于数组，那么就说明买当前水果及当前水果之后的所有水果所要的最少钱就是当前的价钱，因为如果你买前一个水果，你还是要买当前水果
            // 总体思路就是遍历当前水果的免费范围，计算买当前水果和当前水果后面的所有水果所需要金币的最小值
            if (2 * index + 2 >= prices.size()) 
            {
                return prices[index];
            }
            if (!memo.count(index)) 
            {
                int minValue = INT_MAX;
                for (int i = index + 1; i <= 2 * index + 2; i++) 
                {
                    minValue = min(minValue, dp(i));
                }
                memo[index] = prices[index] + minValue;
            }
            return memo[index];
        };

        return dp(0);
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=2412 lang=cpp
 *
 * [2412] 完成所有交易的初始最少钱数
 */

// @lc code=start
class Solution {
public:
    long long minimumMoney(vector<vector<int>>& transactions) {
        long long total_lose = 0;
        int res = 0;
        // 归根到底就是确保遍历的这一次交易不论是亏损还是盈余都可行
        // 已知所有的亏损交易的亏损总和不变，设为t
        // 假如遍历到的是盈余交易，那么就是要保证这次交易前起码有t1的资金确保前面所有的亏损交易亏损额t1与启动资金相减起码大于等于0
        // 所以要确保这次盈余交易成立，那么就起码要t1+cost[i]这么多基础资金
        // 综上所述：
        // 如果这次交易是盈余交易，那么就需要t+cost[i]的钱确保这次交易成立
        // 如果这次交易是亏损交易，那么因为cost[i]已经在t中，所以就需要t - (cost[i] - cashback[i]) + cost[i]这么多钱来开启交易
        // 所以不管怎么说，最后起码要t这么多钱，然后加上max(盈余交易的cost, 亏损交易的cashback)
        for (auto& t : transactions) {
            auto [cost, cashback] = pair(t[0], t[1]);
            total_lose += max(cost - cashback, 0);
            res = max(res, min(cost, cashback));
        }
        return total_lose + res;
    }
};
// @lc code=end


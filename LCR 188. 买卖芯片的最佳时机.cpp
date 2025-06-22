class Solution {
public:
    int bestTiming(vector<int>& prices) {
        vector<int> minm(prices.size(), 0);
        if (prices.size() == 0) return 0;
        minm[0] = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            minm[i] = min(prices[i], minm[i - 1]);
        }
        int res = 0;
        for (int i = 0; i < prices.size(); ++i) {
            res = max(prices[i] - minm[i], res);
        }
        return res;
    }
};
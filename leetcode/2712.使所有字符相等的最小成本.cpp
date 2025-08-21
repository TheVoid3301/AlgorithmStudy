/*
 * @lc app=leetcode.cn id=2712 lang=cpp
 *
 * [2712] 使所有字符相等的最小成本
 */

// @lc code=start
class Solution {
public:
    using ll = long long;
    ll minimumCost(string s) {
        int n = s.size();
        vector<vector<ll>> suf(n + 1, vector<ll>(2, 0));
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '1') {
                suf[i][1] = suf[i + 1][1];
                suf[i][0] = suf[i + 1][1] + (n - i);
            } else {
                suf[i][1] = suf[i + 1][0] + (n - i);
                suf[i][0] = suf[i + 1][0];
            }
        }

        vector<ll> pre(2);
        ll res = 1e18;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                pre[0] = pre[1] + i + 1;
            } else {
                pre[1] = pre[0] + i + 1;
            }
            res = min(res, min(pre[0] + suf[i + 1][0], pre[1] + suf[i + 1][1]));
        }
        return res;
    }
};
// @lc code=end


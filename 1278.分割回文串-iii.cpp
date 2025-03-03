/*
 * @lc app=leetcode.cn id=1278 lang=cpp
 *
 * [1278] 分割回文串 III
 */

// @lc code=start
class Solution {
public:
// 求在l-r的字符串中，变成回文串需要的最少修改次数
    int cost(string& s, int l, int r) {
        int ret = 0;
        for (int i = l, j = r; i < j; ++i, --j) {
            if (s[i] != s[j]) {
                ++ret;
            }
        }
        return ret;
    }

    int palindromePartition(string& s, int k) {
        int n = s.size();
        vector<vector<int>> f(n + 1, vector<int>(k + 1, INT_MAX));
        f[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= min(k, i); ++j) {
                if (j == 1) {
                    f[i][j] = cost(s, 0, i - 1);
                }
                else {
                    for (int i0 = j - 1; i0 < i; ++i0) {
                        f[i][j] = min(f[i][j], f[i0][j - 1] + cost(s, i0, i - 1));
                    }
                }
            }
        }
        
        return f[n][k];
    }
};
// @lc code=end


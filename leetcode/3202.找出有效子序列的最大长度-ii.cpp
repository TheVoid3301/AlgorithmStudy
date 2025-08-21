/*
 * @lc app=leetcode.cn id=3202 lang=cpp
 *
 * [3202] 找出有效子序列的最大长度 II
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int ans = 0;
        vector f(k, vector<int>(k));
        for (auto x : nums) {
            x %= k;
            for (int i = 0; i < k; ++i) {
                f[i][x] = f[x][i] + 1;
                ans = max(ans, f[i][x]);
            }
        }
        return ans;
    }
};
// @lc code=end


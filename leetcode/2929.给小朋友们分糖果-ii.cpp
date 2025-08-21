/*
 * @lc app=leetcode.cn id=2929 lang=cpp
 *
 * [2929] 给小朋友们分糖果 II
 */

// @lc code=start
class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans = 0;
        for (int i = 0; i <= min(limit, n); i++) {
            if (n - i > 2 * limit) {
                continue;
            }
            ans += min(n - i, limit) - max(0, n - i - limit) + 1;
        }
        return ans;
    }
};
// @lc code=end


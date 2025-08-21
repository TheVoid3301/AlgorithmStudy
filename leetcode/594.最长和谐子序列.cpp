/*
 * @lc app=leetcode.cn id=594 lang=cpp
 *
 * [594] 最长和谐子序列
 */

// @lc code=start
class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> sum;
        for (auto i : nums) {
            sum[i]++;
        }
        int res = 0;
        for (auto i : nums) {
            int t = 0;
            if (sum.contains(i - 1)) {
                t += sum[i - 1];
            } else {
                continue;
            }
            t += sum[i];
            res = max(res, t);
        }
        return res;
    }
};
// @lc code=end


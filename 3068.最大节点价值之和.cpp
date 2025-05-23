/*
 * @lc app=leetcode.cn id=3068 lang=cpp
 *
 * [3068] 最大节点价值之和
 */

// @lc code=start
class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k,
                              vector<vector<int>>& edges) {
        long long res = accumulate(nums.begin(), nums.end(), 0ll);
        vector<int> diff;
        for (auto& a : nums) {
            diff.push_back((a ^ k) - a);
        }
        sort(diff.begin(), diff.end());
        for (int i = diff.size() - 1; i > 0 && diff[i] + diff[i - 1] >= 0;
             i -= 2) {
            res += max(0, diff[i] + diff[i - 1]);
        }
        return res;
    }
};
// @lc code=end


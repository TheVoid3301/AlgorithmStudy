/*
 * @lc app=leetcode.cn id=2444 lang=cpp
 *
 * [2444] 统计定界子数组的数目
 */

// @lc code=start
class Solution {
public:
    using ll = long long;
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        ll res = 0;
        int border = -1, last_min = -1, last_max = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < minK || nums[i] > maxK) {
                last_max = -1;
                last_min = -1;
                border = i;
            }
            if (nums[i] == minK) {
                last_min = i;
            }
            if (nums[i] == maxK) {
                last_max = i;
            }
            if (last_min != -1 && last_max != -1) {
                res += min(last_min, last_max) - border;
            }
        }
        return res;
    }
};
// @lc code=end


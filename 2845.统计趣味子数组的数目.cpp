/*
 * @lc app=leetcode.cn id=2845 lang=cpp
 *
 * [2845] 统计趣味子数组的数目
 */

// @lc code=start
class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        unordered_map<int, int> cnt;
        long long res = 0;
        int prefix = 0;
        cnt[0] = 1;
        for (int i = 0; i < n; i++) {
            prefix += nums[i] % modulo == k;
            res += cnt[(prefix - k + modulo) % modulo];
            cnt[prefix % modulo]++;
        }
        return res;
    }
};
// @lc code=end


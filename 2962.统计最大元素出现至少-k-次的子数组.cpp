/*
 * @lc app=leetcode.cn id=2962 lang=cpp
 *
 * [2962] 统计最大元素出现至少 K 次的子数组
 */

// @lc code=start
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        vector<long long> pos{-1};
        for (int i = 0; i < n; i++) {
            if (nums[i] == mx) {
                pos.push_back(i);
            }
        }
        int left = 1, right = k;
        long long ans = 0;
        while (right < pos.size()) {
            ans += (pos[left] - pos[left - 1]) * (n - pos[right]);
            left++, right++;
        }
        return ans;
    }
};

// @lc code=end


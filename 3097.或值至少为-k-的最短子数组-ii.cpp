/*
 * @lc app=leetcode.cn id=3097 lang=cpp
 *
 * [3097] 或值至少为 K 的最短子数组 II
 */

// @lc code=start
class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> bits(30);
        auto calc = [](vector<int> &bits) -> int {
            int ans = 0;
            for (int i = 0; i < bits.size(); i++) {
                if (bits[i] > 0) {
                    ans |= 1 << i;
                }
            }
            return ans;
        };

        int res = INT_MAX;
        for (int left = 0, right = 0; right < n; right++) {
            for (int i = 0; i < 30; i++) {
                bits[i] += (nums[right] >> i) & 1;
            }
            while (left <= right && calc(bits) >= k) {
                res = min(res, right - left + 1);
                for (int i = 0; i < 30; i++) {
                    bits[i] -= (nums[left] >> i) & 1;
                }
                left++;
            }
        }
        
        return res == INT_MAX ? -1: res;
    }
};
// @lc code=end


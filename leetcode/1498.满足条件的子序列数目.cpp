/*
 * @lc app=leetcode.cn id=1498 lang=cpp
 *
 * [1498] 满足条件的子序列数目
 */

// @lc code=start
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        vector<int> v;
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int t = nums[i];
            if (t < target) {
                v[i]++;
            }
            for (int j = 0; j <= i; ++j) {
                if (nums[j] <= (target - t)) {
                    v[i]++;
                }
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < target) {
                res = (res + res + 1) % 1000000007;
            }
        }
        return res;
    }
};
// @lc code=end


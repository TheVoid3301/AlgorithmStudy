/*
 * @Description: 
 * @Auther: thevoid3301
 * @Date: 2025-07-22 00:36:33
 * @LastEditors: thevoid3301
 * @LastEditTime: 2025-07-22 00:36:38
 * @FilePath: \luogu\1695.删除子数组的最大得分.cpp
 */
/*
 * @lc app=leetcode.cn id=1695 lang=cpp
 *
 * [1695] 删除子数组的最大得分
 */

// @lc code=start
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int res = 0, t = 0, l = 0;
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            if (!m.contains(nums[i]) || m[nums[i]] < 1) {
                t += nums[i];
                m[nums[i]]++;
                res = max(res, t);
            } else {
                while (nums[l] != nums[i]) {
                    t -= nums[l];
                    m[nums[l]]--;
                    l++;
                }
                l++;
            }
        }
        return res;
    }
};
// @lc code=end


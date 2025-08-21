/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */

// @lc code=start
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l, r, mid = 0, t;
        if (target == nums[0] || target == nums[nums.size() - 1]) {
            return true;
        }
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < nums[i - 1]) {
                mid = i;
                break;
            }
        }
        if (target > nums[nums.size() - 1]) {
            l = 0;
            r = mid;
            while (l <= r) {
                t = (l + r) / 2;
                if (target == nums[t]) {
                    return true;
                }
                if (target < nums[t]) {
                    r = t - 1;
                } else {
                    l = t + 1;
                }
            }
        } else {
            l = mid;
            r = nums.size() - 1;
            while (l <= r) {
                t = (l + r) / 2;
                if (target == nums[t]) {
                    return true;
                }
                if (target < nums[t]) {
                    r = t - 1;
                } else {
                    l = t + 1;
                }
            }
        }
        return false;
    }
};
// @lc code=end


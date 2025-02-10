/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; ++i) {
            vector<int>::iterator it = nums.begin() + i;
            while (nums[i + 1] == nums[i] && (i + 1) < nums.size()) {
                it = nums.erase(it);
            }
        }
        return nums.size();
    }
};
// @lc code=end


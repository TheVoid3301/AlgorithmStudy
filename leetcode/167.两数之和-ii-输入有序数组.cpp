/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;
        while (l < r) {
            if (numbers[l] + numbers[r] > target) {
                --r;
            } else if (numbers[l] + numbers[r] < target) {
                ++l;
            } else if (numbers[l] + numbers[r] == target) {
                return {l + 1, r + 1};
            }
        }
        return {0, 0};
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=922 lang=cpp
 *
 * [922] 按奇偶排序数组 II
 */

// @lc code=start
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        stack<int> cou;
        for (int i = 1; i < nums.size(); i += 2)
        {
            if (nums[i] % 2 == 0)
            {
                cou.push(i);
            }
        }
        for (int i = 0; i < nums.size(); i += 2)
        {
            if (nums[i] % 2 == 1)
            {
                swap(nums[i], nums[cou.top()]);
                cou.pop();
            }
        }
        return nums;
    }
};
// @lc code=end


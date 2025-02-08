/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除有序数组中的重复项 II
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            if (nums[i] == nums[i + 1])
            {
                if ((i + 2) < nums.size())
                {
                    while (nums[i + 2] == nums[i] && nums.begin() + i + 2 != nums.end())
                    {
                        nums.erase(nums.begin() + i + 2);
                    }
                }
                i++;
            }
        }
        return nums.size();
    }
};
// @lc code=end


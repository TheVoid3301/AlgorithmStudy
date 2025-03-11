/*
 * @lc app=leetcode.cn id=2012 lang=cpp
 *
 * [2012] 数组美丽值求和
 */

// @lc code=start
class Solution {
public:
    // int findMin(vector<int>& nums, int s, int e)
    // {
    //     int res = nums[s];
    //     for (int i = s + 1; i <= e; ++i)
    //     {
    //         res = min(res, nums[i]);
    //     }
    //     return res;
    // }
    // int findMax(vector<int>& nums, int s, int e)
    // {
    //     int res = nums[s];
    //     for (int i = s + 1; i <= e; ++i)
    //     {
    //         res = max(res, nums[i]);
    //     }
    //     return res;
    // }
    int sumOfBeauties(vector<int>& nums) {
        vector<vector<int>> pre(nums.size(), vector<int>(2, 0));
        pre[0][0] = nums[0];
        pre[nums.size() - 1][1] = nums[nums.size() - 1];
        for (int i = 1 ; i < nums.size() - 1; ++i)
        {
            pre[i][0] = max(nums[i - 1], pre[i - 1][0]);
        }
        for (int i = nums.size() - 2 ; i >= 1; --i)
        {
            pre[i][1] = min(nums[i + 1], pre[i + 1][1]);
        }
        int res = 0;
        for (int i = 1; i <= nums.size() - 2; ++i)
        {
            if (nums[i] > pre[i][0] && nums[i] < pre[i][1])
            {
                res += 2;
            }
            else if (nums[i] > nums[i - 1] && nums[i] < nums[i + 1])
            {
                res += 1;
            }
        }
        return res;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1)
        {
            return true;
        }
        vector<int> v(nums.size());
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] != 0)
            {
                for(int j = 1; j <= nums[i]; ++j)
                {
                    if(i + j < nums.size())
                    {
                        v[j + i] = 1;
                    }
                }
            }
            else
            {
                int k = i + 1;
                for(k; k < nums.size(); ++k)
                {
                    if(v[k] == 1)
                    {
                        i = k - 1;
                        break;
                    }
                }
                if(k == nums.size())
                {
                    break;
                }
            }
        }
        if(v[nums.size() - 1] == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
// @lc code=end


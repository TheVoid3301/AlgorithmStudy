/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int r = 0, w = 0, b = 0;
        for(auto i : nums)
        {
            if(i == 0)
            {
                ++r;
            }
            else if(i == 1)
            {
                ++w;
            }
            else if(i == 2)
            {
                ++b;
            }
        }
        nums.clear();
        for(int i = 0; i < r; ++i)
        {
            nums.push_back(0);
        }
        for(int i = 0; i < w; ++i)
        {
            nums.push_back(1);
        }
        for(int i = 0; i < b; ++i)
        {
            nums.push_back(2);
        }
    }
};
// @lc code=end


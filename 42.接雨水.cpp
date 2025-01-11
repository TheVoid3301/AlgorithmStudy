/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() <= 2)
        {
            return 0;
        }
        int l = 0, r = 1, res = 0, now = 0, lastl = 0;
        while(r < height.size())
        {
            if(height[l] > height[r])
            {
                now = now - height[r] + height[l];
                ++r;
            }
            else
            {
                lastl = r;
                res += now;
                now = 0;
                l = r;
                ++r;
            }
        }
        l = height.size() - 2;
        r = height.size() - 1;
        now = 0;
        while(l >= lastl)
        {
            if(height[r] > height[l])
            {
                now = now + height[r] - height[l];
                --l;
            }
            else
            {
                res += now;
                now = 0;
                r = l;
                --l;
            }
        }
        return res;
    }
};
// @lc code=end


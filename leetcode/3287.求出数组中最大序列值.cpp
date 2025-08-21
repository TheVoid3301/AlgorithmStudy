/*
 * @lc app=leetcode.cn id=3287 lang=cpp
 *
 * [3287] 求出数组中最大序列值
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<int> p;
    void huisu(vector<int> nums, int n, int s)
    {
        if(p.size() == n)
        {
            res.push_back(p);
            return ;
        }
        if(p.size() > n)
        {
            return ;
        }
        for(int i = (s + 1); i < nums.size(); ++i)
        {
            p.push_back(nums[i]);
            huisu(nums, n, i);
            p.pop_back();
        }
    }
    int maxValue(vector<int>& nums, int k) {
        int n = 2 * k;
        huisu(nums, n, -1);
        int maxn = 0, l, r;
        for(auto part : res)
        {
            l = 0;
            r = 0;
            for(int i = 0; i < k; ++i)
            {
                l = l | part[i];
            }
            for(int i = k; i < (2 * k); ++i)
            {
                r = r | part[i];
            }
            maxn = max(maxn, l ^ r);
        }
        return maxn;
    }
};
// @lc code=end


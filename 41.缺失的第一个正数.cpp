/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int> s;
        int t = 1;
        for(auto i : nums)
        {
            s.insert(i);
        }
        while(1)
        {
            if(s.find(t) != s.end())
            {
                ++t;
            }
            else
            {
                return t;
            }
        }
        return 0;
    }
};
// @lc code=end


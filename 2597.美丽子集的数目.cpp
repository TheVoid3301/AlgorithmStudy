/*
 * @lc app=leetcode.cn id=2597 lang=cpp
 *
 * [2597] 美丽子集的数目
 */

// @lc code=start
class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int res = 0;
        unordered_map<int, int> cnt;
        function<void(int)> dfs = [&](int i)
        {
            if (i == nums.size())
            {
                res++;
                return ;
            }
            dfs(i + 1);
            if (cnt[nums[i] - k] == 0 && cnt[nums[i] + k] == 0) {
                ++cnt[nums[i]];
                dfs(i + 1);
                --cnt[nums[i]];
            }
        };
        dfs(0);
        return res - 1;
    }
};
// @lc code=end


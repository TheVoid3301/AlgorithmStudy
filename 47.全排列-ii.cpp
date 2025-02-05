/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
public:
    void huisu(set<vector<int>> &res, vector<int> &p, vector<int> &nums, vector<bool> &visited)
    {
        if (p.size() == nums.size())
        {
            res.insert(p);
            return ;
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            if (!visited[i])
            {
                visited[i] = true;
                p.push_back(nums[i]);
                huisu(res, p, nums, visited);
                visited[i] = false;
                p.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> preRes;
        vector<bool> visited(nums.size(), false);
        vector<int> p;
        vector<vector<int>> res;
        huisu(preRes, p, nums, visited);
        for (auto i : preRes)
        {
            res.push_back(i);
        }
        return res;
    }
};
// @lc code=end


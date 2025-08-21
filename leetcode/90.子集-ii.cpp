/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution {
public:
    void huisu(vector<int>& nums, set<vector<int>> &res, vector<bool> &visited, int cou, int &n, vector<int> &p, int s)
    {
        if (cou == n)
        {
            res.insert(p);
            return;
        }
        for (int i = s; i < nums.size(); ++i)
        {
            if (i + (n - cou) - 1 > nums.size())
            {
                return ;
            }
            if (!visited[i])
            {
                visited[i] = true;
                p.push_back(nums[i]);
                huisu(nums, res, visited, cou + 1, n, p, i + 1);
                visited[i] = false;
                p.pop_back();
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> res;
        vector<bool> visited(nums.size(), false);
        vector<int> p = {};
        sort(nums.begin(), nums.end());
        for (int i = 0; i <= nums.size(); ++i)
        {
            huisu(nums, res, visited, 0, i, p, 0);

        }
        vector<vector<int>> resr;
        for (auto i : res)
        {
            resr.push_back(i);
        }
        return resr;
    }
};
// @lc code=end


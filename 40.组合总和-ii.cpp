/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
public:
    void huisu (vector<vector<int>> &res, vector<int>& candidates, int &target, int now, vector<int> &p, int v, int pre) {
        if (now > target) {
            return ;
        }
        if (now == target) {
            res.push_back(p);
            return ;
        }
        for (int i = v; i < candidates.size(); ++i) {
            if (pre == candidates[i]) {
                continue;
            }
            pre = candidates[i];
            p.push_back(candidates[i]);
            huisu(res, candidates, target, now + candidates[i], p, i + 1, -1);
            p.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int now = 0, v = 0;
        vector<bool> visited(candidates.size(), false);
        vector<int> p;
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        huisu(res, candidates, target, now, p, v, -1);
        return res;
    }
};
// @lc code=end


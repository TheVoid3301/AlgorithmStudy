/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution 
{
    public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>> res;
        if(candidates.size() == 0)
        {
            return res;
        }
        vector<int> r;
        sum(res, candidates, 0, 0, target, r);
        return res;
    }
    // start确保每次选取数字时，只能选取该数及该数之后的数字，避免出现[2, 2, 3]和[3, 2, 2]等重复答案
    // t为选取上层数字后，该层数字还需要多少才能到target
    void sum(vector<vector<int>> &res, vector<int> data, int start, int t, int target, vector<int> &r)
    {
        // 若上层数字加完后等于target则将答案push进res
        if(t == target)
        {
            res.push_back(r);
        }
        else
        {
            for(int i = start; i < data.size(); ++i)
            {
                if(t + data[i] <= target)
                {
                    // 如果加上该层遍历的数字没有超过target则递归到下一层
                    r.push_back(data[i]);
                    sum(res, data, i, t + data[i], target, r);
                    // 在下一层遍历完后，应该将该层当前遍历的数字pop出r，然后让该层循环遍历中的下一个数字进入r（即进入下一循环）
                    r.pop_back();
                }
            }
        }
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution {
public:
    void huisu(vector<vector<int>> &res, vector<bool> &visited, int &n, int &k, vector<int> &p, int &sum, int start)
    {
        if (sum == n && p.size() == k)
        {
            res.push_back(p);
            return ;
        }
        for (int i = start; i <= 9; ++i)
        {
            if (!visited[i])
            {
                visited[i] = true;
                sum += i;
                p.push_back(i);
                if (sum > n || p.size() > k)
                {
                    visited[i] = false;
                    sum -= i;
                    p.pop_back();
                    break;
                }
                huisu(res, visited, n, k, p, sum, i + 1);
                visited[i] = false;
                sum -= i;
                p.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<bool> visited(10, false);
        vector<int> p;
        int sum = 0;
        huisu(res, visited, n, k, p, sum, 1);
        return res;
    }
};
// @lc code=end


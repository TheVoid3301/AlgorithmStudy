/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
class Solution {
public:
    int numSquares(int n) 
    {
        vector<int> v(n + 1, INT_MAX);
        v[1] = 1;
        for(int j = 2; j <= n; ++j)
        {
            if((int)sqrt(j) * (int)sqrt(j) == j)
            {
                v[j] = 1;
            }
            else
            {
                for(int k = 1; k <= j / 2; ++k)
                {
                    v[j] = min(v[j], v[k] + v[j - k]);
                }
            }
        }
        return v[n];
    }
};
// @lc code=end


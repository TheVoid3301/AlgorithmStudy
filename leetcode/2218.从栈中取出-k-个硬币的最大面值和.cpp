/*
 * @lc app=leetcode.cn id=2218 lang=cpp
 *
 * [2218] 从栈中取出 K 个硬币的最大面值和
 */

// @lc code=start
class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<int> f(k + 1, -1);
        f[0] = 0;
        // 选取某一个栈开始dp
        for (const auto& pile: piles) 
        {
            // 从最后依次选取硬币开始往前遍历
            for (int i = k; i > 0; --i) 
            {
                int value = 0;
                // 这个循环的意思是连续t次都选某个栈中的值加上i-t次之前的最优情况和之前所得的i次选取的答案哪个大
                for (int t = 1; t <= pile.size(); ++t) 
                {
                    value += pile[t - 1];
                    if (i >= t && f[i - t] != -1) 
                    {
                        f[i] = max(f[i], f[i - t] + value);
                    }
                }
            }
        }
        return f[k];
    }
};

// @lc code=end


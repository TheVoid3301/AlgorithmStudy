/*
 * @lc app=leetcode.cn id=1561 lang=cpp
 *
 * [1561] 你可以获得的最大硬币数目
 */

// @lc code=start
class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end(), [](int a, int b){
            return a > b;
        });
        int res = 0;
        for(int i = 0; i < piles.size() / 3; ++i)
        {
            res += piles[2 * i + 1];
        }
        return res;
    }
};
// @lc code=end


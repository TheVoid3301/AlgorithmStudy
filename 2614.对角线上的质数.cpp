/*
 * @lc app=leetcode.cn id=2614 lang=cpp
 *
 * [2614] 对角线上的质数
 */

// @lc code=start
class Solution {
public:
    int cat(int n) {
        if (n == 1) {
            return 0;
        }
        for (int i = 2; i <= sqrt(n); ++i) {
            if (n % i == 0) {
                return 0;
            }
        }
        return n;
    }
    int diagonalPrime(vector<vector<int>>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            res = max(res, max(cat(nums[i][i]), cat(nums[i][nums.size() - i - 1])));
        }
        return res;
    }
};
// @lc code=end


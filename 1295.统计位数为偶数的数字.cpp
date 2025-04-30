/*
 * @lc app=leetcode.cn id=1295 lang=cpp
 *
 * [1295] 统计位数为偶数的数字
 */

// @lc code=start
class Solution {
public:
    bool check(int i) {
        int n = 0;
        while (i > 0) {
            i /= 10;
            ++n;
        }
        if (n % 2 == 0) {
            return true;
        }
        return false;
    }
    int findNumbers(vector<int>& nums) {
        int res = 0;
        for (auto i : nums) {
            if (check(i)) {
                res++;
            }
        }
        return res;
    }
};
// @lc code=end


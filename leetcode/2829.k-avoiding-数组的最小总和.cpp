/*
 * @lc app=leetcode.cn id=2829 lang=cpp
 *
 * [2829] k-avoiding 数组的最小总和
 */

// @lc code=start
class Solution {
public:
    int minimumSum(int n, int k) {
        map<int, int> inshi;
        for (int i = 1; i <= k / 2; ++i) {
            inshi[i] = k - i;
        }
        int count = 0, res = 0;
        for (auto i = inshi.begin(); i != inshi.end() && count < n; ++i, ++count) {
            res += i -> first;
        }
        while (count < n) {
            res += k;
            ++k;
            ++count;
        }
        return res;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=1399 lang=cpp
 *
 * [1399] 统计最大组的数目
 */

// @lc code=start
class Solution {
public:
    int countSum(int n) {
        int res = 0;
        while (n > 0) {
            res += n % 10;
            n /= 10;
        }
        return res;
    }

    int countLargestGroup(int n) {
        map<int, int> m;
        for (int i = 1; i <= n; ++i) {
            m[countSum(i)]++;
        }
        int maxn = 1;
        for (auto i : m) {
            maxn = max(maxn, i.second);
        }
        int res = 0;
        for (auto i : m) {
            if (i.second == maxn) {
                res++;
            }
        }
        return res;
    }
};
// @lc code=end


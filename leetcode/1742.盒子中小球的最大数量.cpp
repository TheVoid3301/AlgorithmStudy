/*
 * @lc app=leetcode.cn id=1742 lang=cpp
 *
 * [1742] 盒子中小球的最大数量
 */

// @lc code=start
class Solution {
public:
    int countEveryLocation(int n) {
        int sum = 0;
        while (n > 0) {
            sum += (n % 10);
            n = n / 10;
        }
        return sum;
    }
    int countBalls(int lowLimit, int highLimit) {
        map<int, int> m;
        for (int i = lowLimit; i <= highLimit; ++i) {
            m[countEveryLocation(i)]++;
        }
        int res = 0;
        for (auto i : m) {
            res = max(res, i.second);
        }
        return res;
    }
};
// @lc code=end


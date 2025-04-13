/*
 * @lc app=leetcode.cn id=1922 lang=cpp
 *
 * [1922] 统计好数字的数目
 */

// @lc code=start
class Solution {
private:
    static constexpr int mod = 1000000007;
    
public:
    int countGoodNumbers(long long n) {
        // 快速幂求出 x^y % mod
        auto quickmul = [](int x, long long y) -> int {
            int ret = 1, mul = x;
            while (y > 0) {
                if (y % 2 == 1) {
                    ret = (long long)ret * mul % mod;
                }
                mul = (long long)mul * mul % mod;
                y /= 2;
            }
            return ret;
        };
        
        return (long long)quickmul(5, (n + 1) / 2) * quickmul(4, n / 2) % mod;
    }
};
// @lc code=end


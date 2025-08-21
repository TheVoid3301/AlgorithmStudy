/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int numDecodings(std::string s) {
        std::vector<int> dp(s.size());
        if (s[0] != '0') {
            dp[0] = 1;
        }
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] != '0') {
                dp[i] += dp[i - 1];
            }
            if (s[i - 1] == '1' || s[i - 1] == '2' && s[i] <= '6') {
                dp[i] += i - 2 >= 0 ? dp[i - 2] : 1;
            }
        }
        return dp[s.size() - 1];
    }
};
// @lc code=end


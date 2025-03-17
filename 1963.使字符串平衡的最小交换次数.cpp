/*
 * @lc app=leetcode.cn id=1963 lang=cpp
 *
 * [1963] 使字符串平衡的最小交换次数
 */

// @lc code=start
class Solution {
public:
    int minSwaps(string s) {
        auto p = s.begin(), q = s.end() - 1;
        int cnt1{}, cnt2{}, ans{};
        for (; p < q; ) {
            cnt1 += *p++ == '[' ? 1 : -1;
            if (cnt1 < 0) {
                while (cnt2 >= 0)
                    cnt2 += *q-- == '[' ? -1 : 1;
                ans++;
                cnt2 = 1;
                cnt1 = 1;
            }
        }
        return ans;
    }
};
// @lc code=end


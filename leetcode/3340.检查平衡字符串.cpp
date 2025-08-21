/*
 * @lc app=leetcode.cn id=3340 lang=cpp
 *
 * [3340] 检查平衡字符串
 */

// @lc code=start
class Solution {
public:
    bool isBalanced(string num) {
        int onum = 0, jnum = 0;
        bool f = true;
        for (int i = 0; i < num.size(); ++i) {
            if (f) {
                onum += (num[i] - '0');
                f = !f;
            } else {
                jnum += (num[i] - '0');
                f = !f;
            }
        }
        return onum == jnum;
    }
};
// @lc code=end


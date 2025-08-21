/*
 * @lc app=leetcode.cn id=1323 lang=cpp
 *
 * [1323] 6 和 9 组成的最大数字
 */

// @lc code=start
class Solution {
public:
    int maximum69Number (int num) {
        string numstr = to_string(num);
        for (int i = 0; i < numstr.size(); ++i) {
            if (numstr[i] == '6') {
                numstr[i] = '9';
                break;
            }
        }
        return stoi(numstr);
    }
};
// @lc code=end


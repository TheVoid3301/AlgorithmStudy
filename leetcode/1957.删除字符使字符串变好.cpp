/*
 * @Description: 
 * @Auther: thevoid3301
 * @Date: 2025-07-21 00:14:31
 * @LastEditors: thevoid3301
 * @LastEditTime: 2025-07-21 00:24:32
 * @FilePath: \luogu\1957.删除字符使字符串变好.cpp
 */
/*
 * @lc app=leetcode.cn id=1957 lang=cpp
 *
 * [1957] 删除字符使字符串变好
 */

// @lc code=start
#include <string>
using namespace std;
class Solution {
public:
    string makeFancyString(string s) {
        int n = 0;
        char pre = '0';
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != pre || pre == '0') {
                pre = s[i];
                n = 1;
            } else {
                ++n;
                if (n >= 3) {
                    s[i] = '0';
                }
            }
        }
        string res;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != '0') {
                res.push_back(s[i]);
            }
        }
        return res;
    }
};
// @lc code=end


/*
 * @Description: 
 * @Auther: thevoid3301
 * @Date: 2025-07-23 00:06:50
 * @LastEditors: thevoid3301
 * @LastEditTime: 2025-07-23 00:26:33
 * @FilePath: \luogu\1717.删除子字符串的最大得分.cpp
 */
/*
 * @lc app=leetcode.cn id=1717 lang=cpp
 *
 * [1717] 删除子字符串的最大得分
 */

// @lc code=start
class Solution {
public:
    int maximumGain(string a, int x, int y) {
        stack<char> s, t;
        int ret = 0;
        // 处理优化
        if(x > y) {
            swap(x, y);
            reverse(a.begin(), a.end());
        } 
        // 先处理 ba
        for(char c : a) {
            if(c != 'a') s.push(c);
            else {
                // 形成 ba 子字符串
                if(!s.empty() && s.top() == 'b') {
                    s.pop();
                    ret += y;
                } else {
                    s.push(c);
                }
            }
        }
        // 再处理 ab
        while(!s.empty()) {
            char c = s.top();
            s.pop();
            if(c != 'a') t.push(c);
            else {
                if(!t.empty() && t.top() == 'b') {
                    t.pop();
                    ret += x;
                } else {
                    t.push(c);
                }
            }
        }
        return ret;
    }
};
// @lc code=end


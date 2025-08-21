/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
class Solution {
public:
int longestValidParentheses(string s) {
    int maxLen = 0;
    stack<int> st;
    st.push(-1); // 初始化栈，用于处理边界情况

    for (int i = 0; i < s.size(); ++i) 
    {
        if (s[i] == '(') 
        {
            st.push(i); // 将左括号的索引压入栈
        } 
        else 
        {
            st.pop(); // 弹出栈顶的左括号索引
            if (st.empty()) 
            {
                st.push(i); // 如果栈为空，将当前右括号的索引压入栈
            } 
            else 
            {
                maxLen = max(maxLen, i - st.top()); // 更新最大长度
            }
        }
    }
    return maxLen;
}
};
// @lc code=end


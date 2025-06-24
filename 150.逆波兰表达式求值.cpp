/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution {
public:
    bool isnum(string &s) {
        if (s.empty()) return false;
        size_t i = 0;
        if (s[0] == '-') {
            i++;
            if (s.size() == 1) return false; 
        }
        for (; i < s.size(); i++) {
            if (!isdigit(s[i])) {
                return false;
            }
        }
        return true;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (auto c : tokens) {
            if (isnum(c)) {
                s.push(stoi(c));
            } else {
                if (c == "+") {
                    int a = s.top();  
                    s.pop();             
                    int b = s.top();  
                    s.pop();             
                    s.push(a + b);  
                } else if (c == "-") {
                    int a = s.top();  
                    s.pop();             
                    int b = s.top();  
                    s.pop();             
                    s.push(b - a);
                } else if (c == "*") {
                    int a = s.top();  
                    s.pop();             
                    int b = s.top();  
                    s.pop();             
                    s.push(a * b);
                } else if (c == "/") {
                    int a = s.top();  
                    s.pop();             
                    int b = s.top();  
                    s.pop();             
                    s.push(b / a);
                }
            }
        }
        return s.top();
    }
};
// @lc code=end


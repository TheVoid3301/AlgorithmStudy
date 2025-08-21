/*
 * @lc app=leetcode.cn id=224 lang=cpp
 *
 * [224] 基本计算器
 */

// @lc code=start
#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    void trim(string &s) {
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                s.erase(i, 1);
                --i;
            }
        }
    }
    int getDigital(string &s, int &i) {
        int res = 0;
        while(s[i] >= '0' && s[i] <= '9' && i < s.size()) {
            res = res * 10 + (s[i] - '0');
            ++i;
        }
        return res;
    }
    int calculate(string s) {
        trim(s);
        stack<char> ops;
        stack<int> nums;
        nums.push(0);
        int i = 0;
        while (i < s.size()) {
            if (s[i] == '(') {
                ops.push(s[i]);
                ++i;
            } else if (s[i] == ')') {
                while (!ops.empty() && ops.top() != '(') {
                    int b = nums.top(); nums.pop();
                    int a = nums.top(); nums.pop();
                    char op = ops.top(); ops.pop();
                    if (op == '+') {
                        nums.push(a + b);
                    } else if (op == '-') {
                        nums.push(a - b);
                    }
                }
                ops.pop();
                ++i;
            } else if (s[i] == '+' || s[i] == '-') {
                while (!ops.empty() && (ops.top() == '+' || ops.top() == '-')) {
                    int b = nums.top(); nums.pop();
                    int a = nums.top(); nums.pop();
                    char op = ops.top(); ops.pop();
                    if (op == '+') {
                        nums.push(a + b);
                    } else if (op == '-') {
                        nums.push(a - b);
                    }
                }
                ops.push(s[i]);
                ++i;
            } else if (s[i] >= '0' && s[i] <= '9') {
                nums.push(getDigital(s, i));
            }
        }
        while (!ops.empty()) {
            int b = nums.top(); nums.pop();
            int a = nums.top(); nums.pop();
            char op = ops.top(); ops.pop();
            if (op == '+') {
                nums.push(a + b);
            } else if (op == '-') {
                nums.push(a - b);
            }
        }
        return nums.top();
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
class Solution {
public:
    int myAtoi(string s) {
        int sign = 0;
        int sum = 0, cou = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if ((s[i] == '-' || s[i] == '+') && cou == 0)
            {
                if (s[i] == '-')
                {
                    sign = 1;
                }
                cou++;
            }
            else if (cou >= 0 && (s[i] < '0' || s[i] > '9') && s[i] != ' ' || s[i] == ' ' && cou > 0)
            {
                break;
            }
            if (s[i] >= '0' && s[i] <= '9')
            {
                if (sum > INT_MAX / 10 && s[i] >= '0' || sum == INT_MAX / 10 && s[i] >= '7' && sign == 0 || 
                sum  == INT_MAX / 10 && s[i] >= '8' && sign == 1)
                {
                    return sign == 1 ? INT_MIN : INT_MAX;
                }
                cou++;
                sum = sum * 10 + (s[i] - '0');
            }
        }
        return sign == 1 ? -sum : sum;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1, t;
        for (int i = digits.size() - 1; i >= 0; --i)
        {
            t = digits[i] + carry;
            digits[i] = t % 10;
            carry = t / 10;
            if (!carry)
            {
                break;
            }
        }
        if (carry)
        {
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};
// @lc code=end


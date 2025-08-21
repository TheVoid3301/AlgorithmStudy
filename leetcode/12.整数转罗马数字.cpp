/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */

// @lc code=start
class Solution {
public:
    string intToRoman(int num) {
        vector<pair<string, int>> m = {{"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400}, {"C", 100}, 
        {"XC", 90}, {"L", 50}, {"XL", 40}, {"X", 10}, {"IX", 9}, {"V", 5}, {"IV", 4}, {"I", 1}};
        string res = "";
        while (num > 0) {
            for (auto i : m) {
                if (i.second <= num) {
                    res += i.first;
                    num -= i.second;
                    break;
                }
            }
        }
        return res;
    }
};
// @lc code=end


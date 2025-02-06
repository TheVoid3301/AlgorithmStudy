/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> res(numRows, "");
        string sRes;
        int set = 0, f = 1;
        if (numRows == 1)
        {
            return s;
        }
        for (int i = 0; i < s.size(); ++i)
        {
            res[set] += s[i];
            set += f;
            if (set == numRows)
            {
                f = -1;
                set -= 2;
            }
            else if (set == -1)
            {
                f = 1;
                set += 2;
            }
        }
        for (auto i : res)
        {
            sRes += i;
        }
        return sRes;
    }
};
// @lc code=end


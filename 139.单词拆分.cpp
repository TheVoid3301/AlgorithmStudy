/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> res(s.size() + 1, false);
        for (int i = 1; i <= s.size(); ++i)
        {
            string k = s.substr(0, i);
            for (auto p : wordDict)
            {
                if (k == p)
                {
                    res[i - 1] = true;
                }
            }
        }
        for (int i = 0; i < s.size(); ++i)
        {
            if(res[i] == true)
            {
                continue;
            }
            for (int j = 0; j <= i; ++j)
            {
                if (res[j] == true)
                {
                    string t;
                    t = s.substr(j + 1, i - j);
                    for (auto l : wordDict)
                    {
                        if (t == l)
                        {
                            res[i] = true;
                        }
                    }
                }
            }
        }
        return res[s.size() - 1];
    }
};
// @lc code=end


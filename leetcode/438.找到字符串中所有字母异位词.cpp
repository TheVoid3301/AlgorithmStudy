/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> a(26, 0), b(26, 0);
        vector<int> res;
        if(s.size() < p.size())
        {
            return {};
        }
        for(auto i : p)
        {
            a[i - 'a']++;
        }
        for(int i = 0; i < p.size(); ++i)
        {
            b[s[i] - 'a']++;
        }
        if(a == b)
        {
            res.push_back(0);
        }
        for(int i = 1; i <= s.size() - p.size(); ++i)
        {
            b[s[i - 1] - 'a']--;
            b[s[i + p.size() - 1] - 'a']++;
            if(a == b)
            {
                res.push_back(i);
            }
        }
        return res;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

// @lc code=start
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int i = 0, n = s.size();
        vector<int> res;
        while (i < n) {
            char a = s[i];
            int maxr = i;
            for (int k = s.size() - 1; k > i; --k)  {
                if (s[k] == a) {
                    maxr = max(k, maxr);
                    break;
                }
            }
            ++i;
            while (i <= maxr) {
                a = s[i];
                for (int k = s.size() - 1; k > i; --k)  {
                    if (s[k] == a) {
                        maxr = max(k, maxr);
                        break;
                    }
                }
                ++i;
            }
            int num = 0;
            for (auto m : res) {
                num += m;
            }
            res.push_back(maxr - num + 1);
        }
        return res;
    }
};
// @lc code=end


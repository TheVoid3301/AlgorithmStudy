/*
 * @lc app=leetcode.cn id=2900 lang=cpp
 *
 * [2900] 最长相邻不相等子序列 I
 */

// @lc code=start
class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> ans;
        int n = words.size();
        for (int i = 0; i < n; i++) {
            if (i == 0 || groups[i] != groups[i - 1]) {
                ans.emplace_back(words[i]);
            }
        }
        return ans;
    }
};

// @lc code=end


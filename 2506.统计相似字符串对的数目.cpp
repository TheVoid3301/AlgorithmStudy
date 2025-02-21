/*
 * @lc app=leetcode.cn id=2506 lang=cpp
 *
 * [2506] 统计相似字符串对的数目
 */

// @lc code=start
class Solution {
public:
    int similarPairs(vector<string>& words) {
        int res = 0;
        unordered_map<int, int> cnt;
        for (const string& word : words) {
            int state = 0;
            for (char c : word) {
                state |= 1 << (c - 'a');
            }
            res += cnt[state];
            cnt[state]++;
        }
        return res;
    }
};
// @lc code=end


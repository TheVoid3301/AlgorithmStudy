/*
 * @lc app=leetcode.cn id=274 lang=cpp
 *
 * [274] H 指数
 */

// @lc code=start
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), [](int &a, int &b) -> bool
        {
            return a > b;
        });
        for (int i = (int)citations.size(); i >= 1; --i) {
            if (citations[i - 1] >= i) {
                return i;
            }
        }
        return 0;
    }
};
// @lc code=end


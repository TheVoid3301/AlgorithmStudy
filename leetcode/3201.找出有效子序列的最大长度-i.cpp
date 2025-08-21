/*
 * @lc app=leetcode.cn id=3201 lang=cpp
 *
 * [3201] 找出有效子序列的最大长度 I
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int res = 0;
        vector<vector<int>> patterns = {{0, 0}, {0, 1}, 
        {1, 0}, {1, 1}};
        for (auto pattern : patterns) {
            int cnt = 0;
            for (int num : nums) {
                if (num % 2 == pattern[cnt % 2]) {
                    cnt++;
                }
            }
            res = max(res, cnt);
        }
        return res;
    }
};
// @lc code=end


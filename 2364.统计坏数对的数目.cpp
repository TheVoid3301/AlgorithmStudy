/*
 * @lc app=leetcode.cn id=2364 lang=cpp
 *
 * [2364] 统计坏数对的数目
 */

// @lc code=start
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            nums[i] = nums[i] - i;
        }
        map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            res = res + (i - m[nums[i]]);
            m[nums[i]]++;
        }
        return res;
    }
};
// @lc code=end


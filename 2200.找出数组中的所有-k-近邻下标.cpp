/*
 * @lc app=leetcode.cn id=2200 lang=cpp
 *
 * [2200] 找出数组中的所有 K 近邻下标
 */

// @lc code=start
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            int j = max(0, i - k);
            for (j; j <= min(i + k, (int)(nums.size() - 1)); ++j) {
                if (nums[j] == key) {
                    res.push_back(i);
                    break;
                }
            }
        }
        return res;
    }
};
// @lc code=end


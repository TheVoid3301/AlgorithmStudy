/*
 * @lc app=leetcode.cn id=1968 lang=cpp
 *
 * [1968] 构造元素不等于两相邻元素平均值的数组
 */

// @lc code=start
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> res;
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() - 1;
        bool f = true;
        for (int n = 0; n < nums.size(); ++n) {
            if (f) {
                res.push_back(nums[l]);
                l++;
            } else {
                res.push_back(nums[r]);
                r--;
            }
            f = !f;
        }
        return res;
    }
};
// @lc code=end


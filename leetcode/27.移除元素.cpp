/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int res = 0;
        for (vector<int>::iterator i = nums.begin(); i != nums.end(); ++i) {
            if (*i == val) {
                i = nums.erase(i);
                --i;
            } else {
                res++;
            }
        }
        return res;
    }
};
// @lc code=end


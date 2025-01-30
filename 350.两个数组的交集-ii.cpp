/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> cou;
        for (auto i : nums1) {
            cou[i]++;
        }
        vector<int> res;
        for (auto i : nums2) {
            if (cou[i] > 0) {
                res.push_back(i);
                cou[i]--;
            }
        }
        return res;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int p = 0, q = 0;
        vector<int> res;
        while (p < nums1.size() && q < nums2.size()) {
            if (nums1[p] < nums2[q]) {
                res.push_back(nums1[p]);
                ++p;
            } else {
                res.push_back(nums2[q]);
                ++q;
            }
        }
        while (p < nums1.size()) {
            res.push_back(nums1[p]);
            ++p;
        }
        while (q < nums2.size()) {
            res.push_back(nums2[q]);
            ++q;
        }
        if (res.size() % 2 == 0) {
            return 0.5 * (res[res.size() / 2] + res[res.size() / 2 - 1]);
        } else {
            return res[res.size() / 2];
        }
        return 0.0;
    }
};
// @lc code=end


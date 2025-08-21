/*
 * @lc app=leetcode.cn id=1394 lang=cpp
 *
 * [1394] 找出数组中的幸运数
 */

// @lc code=start
class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int, int> m;
        for (auto i : arr) {
            m[i]++;
        }
        int res = -1;
        for (auto i : m) {
            if (i.first == i.second) {
                res = i.first;
            }
        }
        return res;
    }
};
// @lc code=end


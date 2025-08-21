/*
 * @lc app=leetcode.cn id=1287 lang=cpp
 *
 * [1287] 有序数组中出现次数超过25%的元素
 */

// @lc code=start
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        map<int, int> res;
        for (int i = 0; i < arr.size(); ++i) {
            res[arr[i]]++;
        }
        for (auto i : res) {
            if (i.second > (arr.size() / 4)) {
                return i.first;
            }
        }
        return -1;
    }
};// @lc code=end


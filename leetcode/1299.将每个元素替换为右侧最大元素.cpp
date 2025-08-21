/*
 * @lc app=leetcode.cn id=1299 lang=cpp
 *
 * [1299] 将每个元素替换为右侧最大元素
 */

// @lc code=start
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int maxn = 0, start = 0;
        while (start < arr.size() - 1) {
            maxn = start + 1;
            for (int i = start + 1; i < arr.size(); ++i) {
                if (arr[i] >= arr[maxn]) {
                    maxn = i;
                }
            }
            for (int i = start; i < maxn; ++i) {
                arr[i] = arr[maxn];
            }
            start = maxn;
        }
        arr[arr.size() - 1] = -1;
        return arr;
    }
};
// @lc code=end
/*
 * @lc app=leetcode.cn id=3487 lang=cpp
 *
 * [3487] 删除后的最大子数组元素和
 */

// @lc code=start
#include <vector>
#include <set>
#include <climits>
using namespace std;
class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int> s;
        int res = INT_MIN;
        for (auto i : nums) {
            s.insert(i);
            res = max(res, i);
        }
        s.erase(res);
        for (auto i : s) {
            if (i > 0) {
                res += i;
            }
        }
        return res;
    }
};
// @lc code=end


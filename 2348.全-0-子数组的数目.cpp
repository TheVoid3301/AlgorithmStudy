/*
 * @lc app=leetcode.cn id=2348 lang=cpp
 *
 * [2348] 全 0 子数组的数目
 */

// @lc code=start
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        map<int, int> m;
        int k = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                ++k;
            } else {
                if (k > 0) {
                    m[k]++;
                }
                k = 0;
            }
        }
        if (k > 0) {
            m[k]++;
        }
        long long res = 0;
        for (auto &i : m) {
            for (int j = 1; j <= i.first; ++j) {
                res += (long long)(i.first - j + 1) * i.second;
            }
        }
        return res;
    }
};
// @lc code=end


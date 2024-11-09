/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
class Solution{
public:
    static int subarraySum(vector<int>& nums, int aim) {
        unordered_map<int, int> map;
        // 0这个前缀和，在没有任何数字的时候，已经有1次了
        map[0] = 1;
        int ans = 0;
        for (int i = 0, sum = 0; i < nums.size(); i++) {
            // sum : 0...i前缀和
            sum += nums[i];
            ans += map.count(sum - aim) ? map[sum - aim] : 0;
            map[sum]++;
        }
        return ans;
    }
};

// @lc code=end


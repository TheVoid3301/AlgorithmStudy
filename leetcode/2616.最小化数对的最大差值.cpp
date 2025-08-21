/*
 * @lc app=leetcode.cn id=2616 lang=cpp
 *
 * [2616] 最小化数对的最大差值
 */

// @lc code=start
class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        auto check = [&](int mx) -> bool {
            int cnt = 0;
            for (int i = 0; i < nums.size() - 1; i++) {
                if (nums[i + 1] - nums[i] <= mx) {
                    cnt++;
                    i++;
                }
            }
            return cnt >= p;
        };
        int left = 0, right = nums.back() - nums[0];
        while (left < right) {
            int mid = (left + right) >> 1;
            if (check(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};


//dp版本
class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        auto check = [&](int mx) -> bool {
            vector<int> dp(nums.size(), 0);
            if (nums[1] - nums[0] <= mx) {
                dp[1] = 1;
            }
            for (int i = 2; i < nums.size(); i++) {
                if (nums[i] - nums[i - 1] <= mx) {
                    dp[i] = max(dp[i - 2] + 1, dp[i - 1]);
                } else {
                    dp[i] = dp[i - 1];
                }
            }
            return dp[nums.size() - 1] >= p;
        };
        int left = 0, right = nums.back() - nums[0];
        while (left < right) {
            int mid = (left + right) >> 1;
            if (check(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};


// @lc code=end


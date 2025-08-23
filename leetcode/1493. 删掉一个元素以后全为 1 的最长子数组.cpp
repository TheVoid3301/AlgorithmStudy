#include <vector>
using namespace std;
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<pair<int, int>> dp;
        int k = 0;
        int maxLen = 0;
        while (k < nums.size()) {
            if (nums[k] == 1) {
                int count = 0;
                while (k < nums.size() && nums[k] == 1) {
                    count++;
                    k++;
                }
                dp.push_back({k - 1, count});
                maxLen = max(maxLen, count);
                continue;
            }
            k++;
        }
        if (maxLen == nums.size()) {
            return maxLen - 1;
        }
        if (dp.size() == 0) {
            return maxLen;
        }
        for (int i = 0; i < dp.size() - 1; i++) {
            if (dp[i + 1].first - dp[i + 1].second - dp[i].first == 1) {
                maxLen = max(maxLen, dp[i].second + dp[i + 1].second);
            }
        }
        return maxLen;
    }
};
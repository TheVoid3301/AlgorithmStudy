/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        int n = nums.size();
        priority_queue<pair<int, int>> q;
        for(int i = 0; i < k; ++i)
        {
            q.emplace(nums[i], i);
        }
        vector<int> res = {q.top().first};
        for(int i = k; i < n; ++i)
        {
            q.emplace(nums[i], i);
            while(q.top().second <= i - k)
            {
                q.pop();
            }
            res.push_back(q.top().first);
        }
        return res;
    }
};
// @lc code=end


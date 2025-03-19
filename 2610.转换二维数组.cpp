/*
 * @lc app=leetcode.cn id=2610 lang=cpp
 *
 * [2610] 转换二维数组
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int, int> res;
        for (int i = 0; i < nums.size(); ++i) {
            if (res.count(nums[i])) {
                res[nums[i]]++;
            } else {
                res[nums[i]] = 1;
            }
        }
        vector<vector<int>> nu;
        while (!res.empty()) {
            vector<int> p;
            for (auto it = res.begin(); it != res.end(); ) {
                p.push_back(it->first);
                it -> second--;
                if (it->second == 0) {
                    it = res.erase(it);
                } else {
                    ++it;
                }
            }
            nu.push_back(p);
        }
        return nu;
    }
};
// @lc code=end


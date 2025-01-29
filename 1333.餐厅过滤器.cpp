/*
 * @lc app=leetcode.cn id=1333 lang=cpp
 *
 * [1333] 餐厅过滤器
 */

// @lc code=start
class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<int> res;
        sort(restaurants.begin(), restaurants.end(), [](vector<int> &a, vector<int> &b) -> bool{
            if (a[1] == b[1]) {
                return a[0] > b[0];
            }
            return a[1] > b[1];
        });
        for (auto i :restaurants) {
            if (veganFriendly == 0) {
                if (i[3] <= maxPrice && i[4] <= maxDistance) {
                    res.push_back(i[0]);
                }
            } else {
                if (i[3] <= maxPrice && i[4] <= maxDistance && i[2] == 1) {
                    res.push_back(i[0]);
                }
            }
        }
        return res;
    }
};
// @lc code=end


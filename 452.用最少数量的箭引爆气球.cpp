/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */

// @lc code=start
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b) {
            if (a[0] == b[0]) {
                return a[1] < b[1];
            }
            return a[0] < b[0];
        });
        int res = 0;
        int mr = points[0][1];
        for (int i = 1; i < points.size(); ++i) {
            if (points[i][0] <= mr) {
                
            } else {
                res++;
                mr = points[i][1];
            }
            mr = min(mr, points[i][1]);
        }
        return res + 1;
    }
};
// @lc code=end


class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        ranges::sort(points, {}, [](auto& p) { return pair(p[0], -p[1]); });
        int ans = 0;
        for (int i = 0; i < (int)points.size() - 1; ++i) {
            int y1 = points[i][1];
            int max_y = INT_MIN;
            for (int j = i + 1; j < points.size(); ++j) {
                int y2 = points[j][1];
                if (y2 <= y1 && y2 > max_y) {
                    max_y = y2;
                    ans++;
                }
            }
        }
        return ans;
    }
};
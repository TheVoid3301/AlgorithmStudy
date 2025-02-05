class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        sort(rectangles.begin(), rectangles.end(), [](vector<int> &a, vector<int> &b) -> bool
        {
            if (a[1] == b[1])
            {
                return a[3] < b[3];
            }
            return a[1] < b[1]; 
        });
        int start = rectangles[0][3], end = rectangles[rectangles.size() - 1][1];
        for (int i = 1; i < rectangles.size(); ++i)
        {
            if (rectangles[i][1] < start)
            {
                start = max(start, rectangles[i][3]);
            }
        }
        for (int i = rectangles.size() - 2; i >= 0; --i)
        {
            if (rectangles[i][3] > end)
            {
                end = min(end, rectangles[i][1]);
            }
        }
        bool f1 = false, f2 = false;
        for (int i = 0; i < rectangles.size(); ++i)
        {
            if (rectangles[i][1] >= start && rectangles[i][3] <= end)
            {
                f1 = !f1;
                break;
            }
        }
        sort(rectangles.begin(), rectangles.end(), [](vector<int> &a, vector<int> &b) -> bool
        {
            if (a[0] == b[0])
            {
                return a[2] < b[2];
            }
            return a[0] < b[0]; 
        });
        start = rectangles[0][2];
        end = rectangles[rectangles.size() - 1][0];
        for (int i = 1; i < rectangles.size(); ++i)
        {
            if (rectangles[i][0] < start)
            {
                start = max(start, rectangles[i][2]);
            }
        }
        for (int i = rectangles.size() - 2; i >= 0; --i)
        {
            if (rectangles[i][2] > end)
            {
                end = min(end, rectangles[i][0]);
            }
        }
        for (int i = 0; i < rectangles.size(); ++i)
        {
            if (rectangles[i][0] >= start && rectangles[i][2] <= end)
            {
                f2 = !f2;
                break;
            }
        }
        return f1 || f2;
    }
};
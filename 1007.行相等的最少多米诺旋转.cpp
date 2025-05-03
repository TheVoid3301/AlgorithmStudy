/*
 * @lc app=leetcode.cn id=1007 lang=cpp
 *
 * [1007] 行相等的最少多米诺旋转
 */

// @lc code=start
class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        map<int, int> mt, mb;
        int n = tops.size();
        for (auto i : tops) {
            mt[i]++;
        }
        for (auto i : bottoms) {
            mb[i]++;
        }
        bool f = false;
        int res = INT_MAX;
        vector<int> has;
        for (auto i : mt) {
            if (mb.count(i.first)) {
                if (i.second + mb[i.first] >= n) {
                    has.push_back(i.first);
                }
            } else if (i.second == n) {
                res = 0;
            }
        }
        for (auto i : has) {
            int k = 0, j = 0;
            for (j; j < n; ++j) {
                if (tops[j] != i && bottoms[j] == i) {
                    ++k;
                    continue;
                } else if (tops[j] != i && bottoms[j] != i){
                    break;
                }
            }
            if (j == n) {
                f = true;
                res = min(res, k);
            }
        }
        has.clear();
        for (auto i : mb) {
            if (mt.count(i.first)) {
                if (i.second + mt[i.first] >= n) {
                    has.push_back(i.first);
                }
            } else if (i.second == n) {
                res = 0;
            }
        }
        for (auto i : has) {
            int k = 0, j = 0;
            for (j; j < n; ++j) {
                if (bottoms[j] != i && tops[j] == i) {
                    ++k;
                    continue;
                } else if (bottoms[j] != i && tops[j] != i){
                    break;
                }
            }
            if (j == n) {
                f = true;
                res = min(res, k);
            }
        }
        if (!f) {
            return -1;
        } else {
            return res;
        }
    }
};
// @lc code=end


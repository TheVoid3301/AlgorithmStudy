/*
 * @lc app=leetcode.cn id=3274 lang=cpp
 *
 * [3274] 检查棋盘方格颜色是否相同
 */

// @lc code=start
class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        if (abs(coordinate1[0] - coordinate2[0]) % 2 == 1)
        {
            if (abs(coordinate1[1] - coordinate2[1]) % 2 == 1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            if (abs(coordinate1[1] - coordinate2[1]) % 2 == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        return false;
    }
};
// @lc code=end


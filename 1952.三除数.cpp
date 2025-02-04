/*
 * @lc app=leetcode.cn id=1952 lang=cpp
 *
 * [1952] 三除数
 */

// @lc code=start
class Solution {
public:
    bool isThree(int n) {
        int k = 0;
        for (int i  = 1; i <= sqrt(n); ++i)
        {
            if (n % i == 0)
            {
                if (i != sqrt(n))
                {
                    k += 2;
                }
                else
                {
                    k++;
                }
                if (k >= 4)
                {
                    return false;
                }
            }
        }
        if (k != 3)
        {
            return false;
        }
        return true;
    }
};
// @lc code=end


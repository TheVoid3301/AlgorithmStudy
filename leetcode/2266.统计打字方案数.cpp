/*
 * @lc app=leetcode.cn id=2266 lang=cpp
 *
 * [2266] 统计打字方案数
 */

// @lc code=start
class Solution {
public:
    int countTexts(string pressedKeys) {
        int m = 1e9 + 7;
        vector<long long> dp3 = {1, 1, 2, 4};
        vector<long long> dp4 = {1, 1, 2, 4};
        int n = pressedKeys.size();
        for (int i = 4; i < n + 1; ++i) {
            dp3.push_back((dp3[i-1] + dp3[i-2] + dp3[i-3]) % m);
            dp4.push_back((dp4[i-1] + dp4[i-2] + dp4[i-3] + dp4[i-4]) % m);
        }
        long long res = 1;
        int cnt = 1;
        for (int i = 1; i < n; ++i) 
        {
            if (pressedKeys[i] == pressedKeys[i-1]) 
            {
                ++cnt;
            } else {
                if (pressedKeys[i-1] == '7' || pressedKeys[i-1] == '9') 
                {
                    res *= dp4[cnt];
                } 
                else 
                {
                    res *= dp3[cnt];
                }
                res %= m;
                cnt = 1;
            }
        }
        if (pressedKeys[n-1] == '7' || pressedKeys[n-1] == '9') 
        {
            res *= dp4[cnt];
        } 
        else 
        {
            res *= dp3[cnt];
        }
        res %= m;
        return res;
    }
};
// @lc code=end


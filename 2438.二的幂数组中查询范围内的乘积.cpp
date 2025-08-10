/*
 * @lc app=leetcode.cn id=2438 lang=cpp
 *
 * [2438] 二的幂数组中查询范围内的乘积
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> answer(queries.size());
        vector<int> powers;
        int k = 1;
        while (k <= n) {
            k *= 2;
        }
        k /= 2;
        while (n) {
            if (n >= k) {
                powers.push_back(k);
                n -= k;
            } else {
                k /= 2;
            }
        }
        for (int i = 0; i < queries.size(); i++) {
            int product = 1;
            for (int j = queries[i][0]; j <= queries[i][1]; j++) {
                product = (static_cast<long long>(product) * powers[powers.size() - 1 - j]) % 1000000007;
            }
            answer[i] = product % 1000000007;
        }
        return answer;
    }
};
// @lc code=end


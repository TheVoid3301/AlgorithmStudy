#include <bits/stdc++.h>
#include <climits>
using namespace std;

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int minn = INT_MAX, maxn = INT_MIN, n = 0, m = 0;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (num < minn) {
                minn = num;
                n = i;
            }
            if (num > maxn) {
                maxn = num;
                m = i;
            }
        }
        long long res = 0;
        res = ((long long)maxn - minn) * k;
        return res;
    }
};
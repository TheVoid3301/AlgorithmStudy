#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int res = 0;
        for (int num : nums) {
            if (num % 2 == 1) {
                continue;
            }
            res |= num;
        }
        return res;
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size();
        int m = mana.size();
        vector<int> s(n + 1);
        partial_sum(skill.begin(), skill.end(), s.begin() + 1);
        long long start = 0;
        for (int j = 1; j < m; ++j) {
            long long mx = 0;
            for (int i = 0; i < n; ++i) {
                mx = max(mx, 1LL * mana[j - 1] * s[i + 1] - 1LL * mana[j] * s[i]);
            }
            start += mx;
        }
        return start + 1LL * mana[m - 1] * s[n];
    }
};
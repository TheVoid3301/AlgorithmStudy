#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        vector<long long> p(potions.begin(), potions.end());
        for (auto& x : p) {
            x = (long long)ceil((double)success / x);
        }
        sort(p.begin(), p.end(), [](long long a, long long b) {
            return a > b;
        });
        for (auto& x : spells) {
            auto it = lower_bound(p.begin(), p.end(), (long long)x, [](long long a, long long b) {
                return a > b;
            });
            if (it == p.end()) {
                ans.push_back(0);
            } else {
                ans.push_back(p.size() - (it - p.begin()));
            }
        }
        return ans;
    }
};
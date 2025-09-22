#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        set<vector<int>> vis = {nums1};
        vector<vector<int>> q = {nums1};
        for (int ans = 0; ; ans++) {
            vector<vector<int>> nxt;
            for (auto& a : q) {
                if (a == nums2) {
                    return ans;
                }
                for (int l = 0; l < n; l++) {
                    for (int r = l + 1; r <= n; r++) {
                        auto b = a;
                        vector<int> sub(b.begin() + l, b.begin() + r);
                        b.erase(b.begin() + l, b.begin() + r); // 从 b 中移除 sub
                        for (int i = 0; i <= b.size(); i++) {
                            auto c = b;
                            c.insert(c.begin() + i, sub.begin(), sub.end());
                            if (vis.insert(c).second) { // c 不在 vis 中
                                nxt.emplace_back(c);
                            }
                        }
                    }
                }
            }
            q = move(nxt);
        }
    }
};

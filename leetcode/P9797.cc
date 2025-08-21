/*
 * @Description: [NERC 2018] Guest Student
 * @Auther: thevoid3301
 * @Date: 2025-07-31 21:58:53
 * @LastEditors: thevoid3301
 * @LastEditTime: 2025-07-31 22:40:47
 * @FilePath: \luogu\P9797.cc
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int k, t;
        cin >> k;
        vector<int> v;
        for (int j = 0; j < 7; ++j) {
            cin >> t;
            if (t) {
                v.push_back(j);
            }
        }
        int res = INT_MAX;
        for (int j = 0; j < v.size(); ++j) {
            t = v.size() - j;
            if (t >= k) {
                res = min(res, v[j + k - 1] - v[j] + 1);
            } else {
                int kk = k - t;
                int ans = 7 - v[j];
                int l = kk / v.size();
                int r = kk % v.size();
                if (r == 0) {
                    ans += (l - 1) * 7 + v.back() + 1;
                } else {
                    ans += l * 7 + v[r - 1] + 1;
                }
                res = min(res, ans);
            }
        }
        cout << res << '\n';
    }
    return 0;
}
/*
 * @Description: 
 * @Auther: thevoid3301
 * @Date: 2025-07-21 21:26:53
 * @LastEditors: thevoid3301
 * @LastEditTime: 2025-07-21 21:52:30
 * @FilePath: \luogu\合并数列.cc
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> p(n), q(m);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> q[i];
    }
    // sort(p.begin(), p.end());
    // sort(q.begin(), q.end());
    int res = 0;
    int k1 = 0, k2 = 0;
    while (k1 < p.size() && k2 < q.size()) {
        while (p[k1] != q[k2]) {
            if (p[k1] < q[k2]) {
                p[k1] += p[k1 + 1];
                res++;
                p.erase(p.begin() + k1 + 1);
            } else if (p[k1] > q[k2]) {
                q[k2] += q[k2 + 1];
                res++;
                q.erase(q.begin() + k2 + 1);
            }
        }
        k1++;
        k2++;
    }
    cout << res;
    return 0;
}

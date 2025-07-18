/*
 * @Description: 
 * @Auther: thevoid3301
 * @Date: 2025-07-17 23:49:08
 * @LastEditors: thevoid3301
 * @LastEditTime: 2025-07-18 00:49:39
 * @FilePath: \luogu\拔河.cc
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> v(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int l = 0, r = n - 1;
    long long res = 0;
    while(l <= r) {
        while (res >= 0 && l <= r) {
            res -= v[l++];
        }
        while (res < 0 && l <= r) {
            res += v[r--];
        }
    }
    cout << abs(res);
    return 0;
}